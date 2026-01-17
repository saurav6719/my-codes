# Fair Influence Maximization Pipeline
# Combined, optimized, and experiment-ready implementation.
# Use this as a single script/notebook module. Save as fair_im_pipeline.py or paste into a Jupyter cell.

"""
Features included:
- Safe graph loading with id->index mapping
- Adversarial autoencoder embedder (TensorFlow) with tf.data and @tf.function
- Fixed, vectorized seed selection from embeddings (MiniBatchKMeans)
- Parallel Monte Carlo IC simulation
- Reverse Reachable (RR) set builder (IMM-style skeleton) and greedy selection
- Group-aware budget allocation and max-min greedy variant
- Evaluation & logging utilities (spread, per-group spread, min, max, gini, runtime)
- Experiment runner that compares: original embedding-seed pipeline, centrality baseline,
  metaheuristic placeholder (particle swarm skeleton), and new ABRIS/IMM + max-min method
- Outputs CSV/Excel with detailed logs per k and per method

Notes:
- This is ready-to-run but may need adjusting paths (edges/attr files) and package installs.
- For very large graphs you should increase theta (RR sets) and/or implement C++/numba bottlenecks.
"""

import time
import random
import math
import csv
import pickle
import numpy as np
import pandas as pd
import networkx as nx
from collections import defaultdict, Counter
from sklearn.cluster import MiniBatchKMeans
from sklearn.metrics import pairwise_distances_argmin_min
import multiprocessing as mp
import os

# TensorFlow parts (for embedder)
import tensorflow as tf
from tensorflow.keras import Sequential, Model
from tensorflow.keras.layers import Dense, Dropout, Input

# Set seeds for reproducibility
SEED = 0
random.seed(SEED)
np.random.seed(SEED)
tf.random.set_seed(SEED)

# -----------------------------
# Utility / Metrics
# -----------------------------

def gini(array):
    arr = np.array(array, dtype=float)
    if arr.size == 0:
        return 0.0
    arr = arr.flatten()
    if np.amin(arr) < 0:
        arr -= np.amin(arr)
    mean = arr.mean()
    if mean == 0:
        return 0.0
    diffsum = np.sum(np.abs(arr[:, None] - arr[None, :]))
    return diffsum / (2 * arr.size**2 * mean)


def fairness_metrics_from_counts(counts, group_sizes, total_nodes):
    # counts: list of influenced counts per group
    spreads = [c / max(1, s) for c, s in zip(counts, group_sizes)]
    total_spread = sum(counts)
    min_sp = min(spreads)
    max_sp = max(spreads)
    gap = max_sp - min_sp
    g = gini(spreads)
    return {
        'spreads': spreads,
        'total_spread': total_spread,
        'min_spread': min_sp,
        'max_spread': max_sp,
        'gap': gap,
        'gini': g
    }

# -----------------------------
# Graph loading with stable mapping
# -----------------------------

def load_graph_with_attrs(edges_path, attr_path=None, remove_age_gt=None):
    """
    edges_path: tab-separated file with two columns (s, t) or pandas-readable format
    attr_path: tab-separated file with columns ['id','College','Age','Major'] (optional)
    remove_age_gt: if provided, remove nodes with Age > this

    Returns: G (nx.Graph relabeled 0..n-1), id2idx mapping, original_nodes_list
    """
    # load edges
    edges_df = pd.read_csv(edges_path, sep="\t", header=None, comment='#', engine='python')
    if edges_df.shape[1] < 2:
        raise ValueError('edges file must have at least 2 columns')
    edges_df = edges_df.iloc[:, :2]
    edges_df.columns = ['s', 't']

    # build graph with original ids
    G_orig = nx.from_pandas_edgelist(edges_df, source='s', target='t', create_using=nx.Graph())

    id2attrs = {}
    if attr_path is not None:
        attr_df = pd.read_csv(attr_path, sep='\t', header=None, comment='#', engine='python')
        # try to infer columns
        if attr_df.shape[1] >= 4:
            attr_df = attr_df.iloc[:, :4]
            attr_df.columns = ['id', 'College', 'Age', 'Major']
            for _, r in attr_df.iterrows():
                id2attrs[r['id']] = {'College': r['College'], 'Age': r['Age'], 'Major': r['Major']}

    # remove nodes by age if requested
    if remove_age_gt is not None and id2attrs:
        to_remove = set([nid for nid, a in id2attrs.items() if 'Age' in a and pd.notnull(a['Age']) and a['Age'] > remove_age_gt])
        for node in list(G_orig.nodes()):
            if node in to_remove:
                if G_orig.has_node(node):
                    G_orig.remove_node(node)

    # stable sorted nodes
    nodes_sorted = sorted(G_orig.nodes())
    id2idx = {nid: idx for idx, nid in enumerate(nodes_sorted)}
    G = nx.relabel_nodes(G_orig, id2idx, copy=True)

    return G, id2idx, nodes_sorted

# -----------------------------
# Embedding: adversarial autoencoder
# -----------------------------

def build_encoder(embedding_size):
    model = Sequential([
        Dense(embedding_size * 4, activation='relu'),
        Dense(embedding_size * 2, activation='relu'),
        Dense(embedding_size, activation='relu')
    ])
    return model


def build_decoder(embedding_size, output_size):
    model = Sequential([
        Dense(embedding_size * 2, activation='relu'),
        Dense(embedding_size * 4, activation='relu'),
        Dense(output_size, activation='sigmoid')
    ])
    return model


def build_discriminator(embedding_size):
    model = Sequential([
        Input(shape=(embedding_size,)),
        Dense(25, activation='relu'), Dropout(0.25),
        Dense(15, activation='relu'), Dropout(0.2),
        Dense(6, activation='relu'), Dropout(0.2),
        Dense(1, activation='sigmoid')
    ])
    return model


def recon_loss(x, x_hat):
    return tf.reduce_sum(tf.keras.losses.binary_crossentropy(x, x_hat))


def first_order_loss(X, Z):
    X = tf.cast(X, tf.float32)
    Z = tf.cast(Z, tf.float32)
    D = tf.linalg.diag(tf.reduce_sum(X, 1))
    L = D - X
    return 2 * tf.linalg.trace(tf.matmul(tf.matmul(tf.transpose(Z), L), Z))


def ae_adversarial_loss(X, Z, x, x_hat, d_z0, d_z1, first_order, alpha):
    reccon_loss = recon_loss(x, x_hat)
    f1_loss = first_order_loss(X, Z)
    if first_order == 'with_f1':
        reccon_loss += alpha * f1_loss
    adversarial_loss = tf.reduce_sum(tf.keras.losses.binary_crossentropy(tf.ones_like(d_z0), d_z0)) + \
                       tf.reduce_sum(tf.keras.losses.binary_crossentropy(tf.zeros_like(d_z1), d_z1))
    return reccon_loss + 10 * adversarial_loss


def ae_accuracy(x, x_hat):
    round_x_hat = tf.round(x_hat)
    return tf.reduce_mean(tf.cast(tf.equal(x, round_x_hat), tf.float32))

# Training steps compiled
@tf.function
def pretrain_step_embd_tf(X_batch, encoder, decoder, auto_encoder, pre_optimizer, first_order, alpha):
    with tf.GradientTape() as tape:
        z = encoder(X_batch, training=True)
        x_hat = decoder(z, training=True)
        Z = encoder(X_batch, training=True)
        loss = recon_loss(X_batch, x_hat)
        if first_order == 'with_f1':
            loss += alpha * first_order_loss(X_batch, Z)
    grads = tape.gradient(loss, auto_encoder.trainable_variables)
    pre_optimizer.apply_gradients(zip(grads, auto_encoder.trainable_variables))
    acc = ae_accuracy(X_batch, x_hat)
    return loss, acc


def pretrain_embd_tf(X, encoder, decoder, auto_encoder, pre_optimizer, first_order='no_f1', alpha=0.05, batch_size=64, epochs=50):
    dataset = tf.data.Dataset.from_tensor_slices(X.astype(np.float32)).shuffle(buffer_size=len(X)).batch(batch_size).prefetch(tf.data.AUTOTUNE)
    for epoch in range(epochs):
        losses = []
        accs = []
        for batch in dataset:
            loss, acc = pretrain_step_embd_tf(batch, encoder, decoder, auto_encoder, pre_optimizer, first_order, alpha)
            losses.append(loss.numpy())
            accs.append(acc.numpy())
        if epoch % 10 == 0:
            print(f"Pretrain epoch {epoch}: loss={np.mean(losses):.4f}, acc={np.mean(accs):.4f}")

# Full adversarial joint step
@tf.function
def train_step_adv(X_batch, x0_batch, x1_batch, encoder, decoder, auto_encoder, discriminator, ae_optimizer, disc_optimizer, first_order, alpha):
    with tf.GradientTape() as ae_tape, tf.GradientTape() as disc_tape:
        z0 = encoder(x0_batch, training=True)
        z1 = encoder(x1_batch, training=True)
        Z = encoder(X_batch, training=True)
        d_z0 = discriminator(z0, training=True)
        d_z1 = discriminator(z1, training=True)
        x0_hat = decoder(z0, training=True)
        x1_hat = decoder(z1, training=True)
        ae_loss = ae_adversarial_loss(X_batch, Z, tf.concat([x0_batch, x1_batch], 0), tf.concat([x0_hat, x1_hat], 0), d_z0, d_z1, first_order, alpha)
        disc_loss = tf.reduce_mean(tf.keras.losses.binary_crossentropy(tf.zeros_like(d_z0), d_z0) + tf.keras.losses.binary_crossentropy(tf.ones_like(d_z1), d_z1))
    gradients_ae = ae_tape.gradient(ae_loss, auto_encoder.trainable_variables)
    gradients_disc = disc_tape.gradient(disc_loss, discriminator.trainable_variables)
    ae_optimizer.apply_gradients(zip(gradients_ae, auto_encoder.trainable_variables))
    disc_optimizer.apply_gradients(zip(gradients_disc, discriminator.trainable_variables))
    ae_acc = ae_accuracy(tf.concat([x0_batch, x1_batch], 0), tf.concat([x0_hat, x1_hat], 0))
    return ae_loss, ae_acc, disc_loss


def adversarial_train_tf(X, idxs_zeros, idxs_ones, encoder, decoder, auto_encoder, discriminator, ae_optimizer, disc_optimizer, first_order='no_f1', alpha=0.05, epochs=200, batch_size=64):
    # create dataset of indices and then batches of x0/x1
    n = X.shape[0]
    idxs_zeros = np.array(idxs_zeros)
    idxs_ones = np.array(idxs_ones)
    for epoch in range(epochs):
        np.random.shuffle(idxs_zeros)
        np.random.shuffle(idxs_ones)
        losses = []
        accs = []
        for i in range(0, len(idxs_ones), batch_size):
            sel0 = idxs_zeros[i:i+batch_size]
            sel1 = idxs_ones[i:i+batch_size]
            if len(sel0) == 0 or len(sel1) == 0:
                continue
            x0 = tf.cast(X[sel0], tf.float32)
            x1 = tf.cast(X[sel1], tf.float32)
            Xfull = tf.cast(X, tf.float32)
            ae_loss, ae_acc, disc_loss = train_step_adv(Xfull, x0, x1, encoder, decoder, auto_encoder, discriminator, ae_optimizer, disc_optimizer, first_order, alpha)
            losses.append(ae_loss.numpy())
            accs.append(ae_acc.numpy())
        if epoch % 20 == 0:
            print(f"Adv epoch {epoch}: loss={np.mean(losses):.4f} acc={np.mean(accs):.4f}")

# -----------------------------
# Seed selection from embeddings
# -----------------------------

def get_seeds_from_embeddings(embedding, nodes, labels, strategy, n_seeds, n_clusters=8):
    embedding = np.asarray(embedding)
    nodes = np.asarray(nodes)
    labels = np.asarray(labels)
    kmeans = MiniBatchKMeans(n_clusters=n_clusters, batch_size=256, random_state=SEED)
    kmeans.fit(embedding)
    cluster_number = kmeans.labels_
    centers = kmeans.cluster_centers_
    seed_ids = []
    for c in range(n_clusters):
        members = np.where(cluster_number == c)[0]
        if len(members) == 0:
            continue
        dists = np.linalg.norm(embedding[members] - centers[c], axis=1)
        sorted_members = members[np.argsort(dists)]
        if strategy == 'nearest':
            chosen = sorted_members[:n_seeds]
            seed_ids.extend(list(nodes[chosen]))
        elif strategy == 're-cluster':
            labels_in = labels[members]
            zero_idx = members[labels_in == 0]
            one_idx = members[labels_in == 1]
            total = len(members)
            prop_zero = int(round((len(zero_idx) / total) * n_seeds))
            prop_one = n_seeds - prop_zero
            chosen = []
            if len(zero_idx) > 0 and prop_zero > 0:
                d0 = np.linalg.norm(embedding[zero_idx] - centers[c], axis=1)
                chosen0 = zero_idx[np.argsort(d0)][:prop_zero]
                chosen.extend(list(nodes[chosen0]))
            if len(one_idx) > 0 and prop_one > 0:
                d1 = np.linalg.norm(embedding[one_idx] - centers[c], axis=1)
                chosen1 = one_idx[np.argsort(d1)][:prop_one]
                chosen.extend(list(nodes[chosen1]))
            if len(chosen) < n_seeds:
                for idx in sorted_members:
                    if nodes[idx] not in chosen:
                        chosen.append(nodes[idx])
                    if len(chosen) == n_seeds:
                        break
            seed_ids.extend(chosen)
        else:
            raise ValueError('Unknown strategy')
    return np.array(seed_ids, dtype=int)

# -----------------------------
# IC simulation (parallelized)
# -----------------------------

def _single_ic_run(args):
    adj_list, seeds, imp_prob, recover_prob, remove = args
    impressed = set(seeds)
    front = list(seeds)
    removed = set()
    while front:
        new_front = []
        for node in front:
            for neigh in adj_list[node]:
                if neigh in impressed or neigh in removed or neigh in new_front:
                    continue
                if random.random() < imp_prob:
                    new_front.append(neigh)
        # recovery handling (if used)
        if recover_prob and len(impressed) > 0:
            impressed_list = list(impressed)
            draws = np.random.random(len(impressed_list))
            if remove:
                for i, val in enumerate(draws):
                    if val < recover_prob:
                        removed.add(impressed_list[i])
                        if impressed_list[i] in impressed:
                            impressed.remove(impressed_list[i])
            else:
                impressed = set([impressed_list[i] for i in range(len(draws)) if draws[i] >= recover_prob])
        impressed.update(front)
        front = new_front
    return impressed


def repeated_IC_parallel(G, seeds, n_expr=500, imp_prob=0.01, recover_prob=0, remove=0, n_workers=None):
    if n_workers is None:
        n_workers = max(1, mp.cpu_count() - 1)
    adj = {int(n): [int(x) for x in G.neighbors(n)] for n in G.nodes()}
    args = [(adj, list(map(int, seeds)), imp_prob, recover_prob, remove) for _ in range(n_expr)]
    with mp.Pool(processes=n_workers) as pool:
        results = pool.map(_single_ic_run, args)
    zeros_count = []
    ones_count = []
    total_count = []
    # group detection not available here; caller should compute counts
    for impressed in results:
        total_count.append(len(impressed))
        zeros_count.append(len(impressed))
        ones_count.append(0)
    return results

# Helper: deterministic single run (for thresholded diffusion in code2)

def simulate_threshold_diffusion(graph, seeds):
    # graph: networkx with edge attribute 'p' and node attribute 't'
    influenced = list(seeds)
    queue = list(seeds)
    pre_node_record = defaultdict(float)
    while queue:
        node = queue.pop(0)
        for nbr in graph[node]:
            if nbr in influenced:
                continue
            p = graph[node][nbr].get('p', 0.01)
            pre_node_record[nbr] += p
            if pre_node_record[nbr] >= graph.nodes[nbr].get('t', 1.0):
                influenced.append(nbr)
                queue.append(nbr)
    return influenced

# -----------------------------
# Reverse Reachable (RR) sets and greedy selection (IMM-style skeleton)
# -----------------------------

def build_reversed_adj(G):
    rev = defaultdict(list)
    for u, v in G.edges():
        rev[int(v)].append(int(u))
    return rev


def generate_rr_set_ic(rev_adj, p):
    v = random.choice(list(rev_adj.keys()))
    rr = set([v])
    queue = [v]
    while queue:
        cur = queue.pop()
        for u in rev_adj[cur]:
            if u in rr:
                continue
            if random.random() < p:
                rr.add(u)
                queue.append(u)
    return rr


def build_rr_sets(G, p, theta):
    rev_adj = build_reversed_adj(G)
    rr_sets = []
    for _ in range(theta):
        rr_sets.append(generate_rr_set_ic(rev_adj, p))
    return rr_sets


def select_seed_via_rr(rr_sets, k):
    cover_count = Counter()
    rr_index_containing = defaultdict(list)
    for i, rr in enumerate(rr_sets):
        for node in rr:
            cover_count[node] += 1
            rr_index_containing[node].append(i)
    selected = []
    covered = set()
    for _ in range(k):
        if not cover_count:
            break
        node, _ = cover_count.most_common(1)[0]
        selected.append(node)
        for idx in rr_index_containing[node]:
            if idx in covered:
                continue
            covered.add(idx)
            for u in rr_sets[idx]:
                cover_count[u] -= 1
                if cover_count[u] <= 0:
                    del cover_count[u]
        if node in cover_count:
            del cover_count[node]
    return selected

# Group-aware max-min greedy using RR-sets

def select_seed_maxmin_rr(rr_sets, node2group, group_counts_target, k):
    # rr_sets: list of sets
    # node2group: dict node->group_idx
    # group_counts_target: number of RR-sets per group (proportional) or None
    m = max(node2group.values()) + 1
    # precompute for each RR-set which group the root belongs to (approx)
    rr_group = []
    for rr in rr_sets:
        # choose a representative node (the original sampled node), but we don't have it stored.
        # fallback: infer group by majority of nodes in rr
        grp_counts = Counter([node2group.get(u, 0) for u in rr])
        rr_group.append(grp_counts.most_common(1)[0][0])
    # maintain uncovered rr_set indices per group
    rr_by_group = defaultdict(set)
    for i, g in enumerate(rr_group):
        rr_by_group[g].add(i)
    covered = set()
    selected = []
    cover_count = Counter()
    rr_index_containing = defaultdict(list)
    for i, rr in enumerate(rr_sets):
        for node in rr:
            cover_count[node] += 1
            rr_index_containing[node].append(i)
    group_cov = [0] * m
    for _ in range(k):
        # score node by improvement in min normalized coverage
        best_node = None
        best_score = -1
        for node, _ in cover_count.items():
            # simulate roughly: for each rr this node covers, mark group gain
            gain_per_group = [0] * m
            for idx in rr_index_containing[node]:
                if idx in covered:
                    continue
                g = rr_group[idx]
                gain_per_group[g] += 1
            # normalized new coverage
            norms = []
            for g in range(m):
                denom = max(1, len(rr_by_group[g]))
                norms.append((group_cov[g] + gain_per_group[g]) / denom)
            score = min(norms)  # maximize the minimum
            if score > best_score:
                best_score = score
                best_node = node
        if best_node is None:
            break
        selected.append(best_node)
        # apply coverage
        for idx in rr_index_containing[best_node]:
            if idx in covered:
                continue
            covered.add(idx)
            g = rr_group[idx]
            group_cov[g] += 1
            for u in rr_sets[idx]:
                if u in cover_count:
                    cover_count[u] -= 1
                    if cover_count[u] <= 0:
                        del cover_count[u]
    return selected

# -----------------------------
# Baselines & metaheuristic placeholder
# -----------------------------

def top_k_degree(G, k):
    deg = dict(G.degree())
    items = sorted(deg.items(), key=lambda x: -x[1])[:k]
    return [int(x[0]) for x in items]

# A simple random-restart greedy local search as a lightweight metaheuristic

def local_search_greedy(G, k, n_restarts=10, eval_fn=None, budget_seconds=30):
    start = time.time()
    best = None
    best_score = -1
    nodes = list(G.nodes())
    while time.time() - start < budget_seconds:
        seed = random.sample(nodes, k)
        improved = True
        while improved and time.time() - start < budget_seconds:
            improved = False
            for i in range(k):
                cur = seed[i]
                for cand in random.sample(nodes, 50):
                    if cand in seed:
                        continue
                    new_seed = seed[:i] + [cand] + seed[i+1:]
                    if eval_fn is None:
                        # evaluate via one deterministic threshold sim
                        inf = simulate_threshold_diffusion(G, new_seed)
                        score = len(inf)
                    else:
                        score = eval_fn(new_seed)
                    if score > best_score:
                        best_score = score
                        best = new_seed
                        seed = new_seed
                        improved = True
            # inner loop
        if time.time() - start > budget_seconds:
            break
    return best if best is not None else random.sample(nodes, k)

# -----------------------------
# Evaluation harness and experiment runner
# -----------------------------

def evaluate_seedset_ic(G, seeds, nodes_by_group, group_sizes, n_expr=500, imp_prob=0.01, parallel=True):
    # If parallel MC available and graph not too small, use repeated_IC_parallel
    if parallel:
        results = repeated_IC_parallel(G, seeds, n_expr=n_expr, imp_prob=imp_prob)
        # results is list of impressed sets
        counts_per_run = []
        for impressed in results:
            counts = [len(set(impressed) & set(g)) for g in nodes_by_group]
            counts_per_run.append(counts)
        mean_counts = np.mean(counts_per_run, axis=0).tolist()
        metrics = fairness_metrics_from_counts(mean_counts, [len(g) for g in nodes_by_group], G.number_of_nodes())
        return metrics
    else:
        # single deterministic threshold diffusion for quick check
        influenced = simulate_threshold_diffusion(G, seeds)
        counts = [len(set(influenced) & set(g)) for g in nodes_by_group]
        metrics = fairness_metrics_from_counts(counts, [len(g) for g in nodes_by_group], G.number_of_nodes())
        return metrics


def run_experiments(edges_path, attr_path=None, remove_age_gt=None, ks=[10,20,30,40,50], methods=None, out_csv='experiment_results.csv', p_ic=0.01, rr_theta=20000):
    # Load graph
    G, id2idx, orig_nodes = load_graph_with_attrs(edges_path, attr_path, remove_age_gt)
    n = G.number_of_nodes()
    nodes = list(range(n))

    # Build groups: if attr_path provided and 'Age' existed, build two groups 0/1 else use community detection
    nodes_by_group = []
    labels = np.zeros(n, dtype=int)
    if attr_path is not None:
        # try to read attribute mapping (best-effort)
        try:
            attr_df = pd.read_csv(attr_path, sep='\t', header=None, comment='#', engine='python')
            if attr_df.shape[1] >= 3:
                attr_df = attr_df.iloc[:, :4]
                attr_df.columns = ['id', 'College', 'Age', 'Major']
                # build label 0 if Age<20 else 1
                id2label = {}
                for _, r in attr_df.iterrows():
                    if r['id'] in id2idx:
                        id2label[id2idx[r['id']]] = 0 if r['Age'] < 20 else 1
                # build groups
                g0 = [i for i in nodes if id2label.get(i, 0) == 0]
                g1 = [i for i in nodes if id2label.get(i, 0) == 1]
                nodes_by_group = [g0, g1]
                labels = np.array([id2label.get(i, 0) for i in nodes])
        except Exception:
            nodes_by_group = [nodes]
    if not nodes_by_group:
        # fallback: simple community detection via greedy modularity
        communities = list(nx.algorithms.community.greedy_modularity_communities(G))
        nodes_by_group = [list(c) for c in communities[:2]] if len(communities) >= 2 else [nodes]
        labels = np.zeros(n, dtype=int)
        for gi, group in enumerate(nodes_by_group):
            for v in group:
                labels[v] = gi

    group_sizes = [len(g) for g in nodes_by_group]
    node2group = {v: int(labels[v]) for v in nodes}

    # Precompute adjacency list
    adj = [list(G.neighbors(i)) for i in nodes]

    # Precompute RR-sets for IMM-based methods (can be reused across k)
    print('Building RR sets (theta=', rr_theta, ')...')
    rr_sets = build_rr_sets(G, p_ic, rr_theta)
    print('Built', len(rr_sets), 'RR sets')

    # Prepare model functions
    results = []

    # Baseline methods: embedding-based seed (from Code1), centrality (code2), local_search_greedy, IMM-maxmin
    for k in ks:
        print('\nRunning experiments for k=', k)
        row_common = {'k': k, 'n': n}

        # 1) Embedding baseline (train small embedder)
        try:
            X = nx.to_numpy_array(G)
            embedding_size = 32
            encoder = build_encoder(embedding_size)
            decoder = build_decoder(embedding_size, n)
            autoenc_input = Input(shape=(n,))
            auto_encoder = Model(autoenc_input, decoder(encoder(autoenc_input)))
            discriminator = build_discriminator(embedding_size)
            pre_optimizer = tf.keras.optimizers.Adam(1e-3)
            pretrain_embd_tf(X, encoder, decoder, auto_encoder, pre_optimizer, first_order='no_f1', epochs=20, batch_size=128)
            # get embeddings
            embeddings = encoder(X.astype(np.float32)).numpy()
            seeds_emb = get_seeds_from_embeddings(embeddings, nodes, labels, 're-cluster', int(math.ceil(k / max(1, 8))), n_clusters=8)
            seeds_emb = seeds_emb[:k]
            t0 = time.time()
            metrics_emb = evaluate_seedset_ic(G, seeds_emb, nodes_by_group, group_sizes, n_expr=200, imp_prob=p_ic, parallel=True)
            t1 = time.time()
            row = dict(row_common)
            row.update({'method': 'embedding_baseline', 'time': t1 - t0, **metrics_emb})
            results.append(row)
        except Exception as e:
            print('Embedding baseline failed:', e)

        # 2) Centrality baseline (degree)
        try:
            seeds_deg = top_k_degree(G, k)
            t0 = time.time()
            metrics_deg = evaluate_seedset_ic(G, seeds_deg, nodes_by_group, group_sizes, n_expr=200, imp_prob=p_ic, parallel=True)
            t1 = time.time()
            row = dict(row_common)
            row.update({'method': 'degree_baseline', 'time': t1 - t0, **metrics_deg})
            results.append(row)
        except Exception as e:
            print('Degree baseline failed:', e)

        # 3) Local-search metaheuristic
        try:
            t0 = time.time()
            best_local = local_search_greedy(G, k, n_restarts=5, eval_fn=None, budget_seconds=15)
            t1 = time.time()
            metrics_local = evaluate_seedset_ic(G, best_local, nodes_by_group, group_sizes, n_expr=200, imp_prob=p_ic, parallel=True)
            row = dict(row_common)
            row.update({'method': 'local_search', 'time': t1 - t0, **metrics_local})
            results.append(row)
        except Exception as e:
            print('Local search failed:', e)

        # 4) IMM / RR greedy (total spread)
        try:
            t0 = time.time()
            seeds_rr = select_seed_via_rr(rr_sets, k)
            t1 = time.time()
            metrics_rr = evaluate_seedset_ic(G, seeds_rr, nodes_by_group, group_sizes, n_expr=200, imp_prob=p_ic, parallel=True)
            row = dict(row_common)
            row.update({'method': 'IMM_greedy', 'time': t1 - t0, **metrics_rr})
            results.append(row)
        except Exception as e:
            print('IMM greedy failed:', e)

        # 5) Group-aware max-min using RR sets (our improved method)
        try:
            t0 = time.time()
            seeds_mm = select_seed_maxmin_rr(rr_sets, node2group, None, k)
            t1 = time.time()
            metrics_mm = evaluate_seedset_ic(G, seeds_mm, nodes_by_group, group_sizes, n_expr=200, imp_prob=p_ic, parallel=True)
            row = dict(row_common)
            row.update({'method': 'IMM_maxmin_groupaware', 'time': t1 - t0, **metrics_mm})
            results.append(row)
        except Exception as e:
            print('IMM maxmin failed:', e)

    # Save results
    df = pd.DataFrame(results)
    df.to_csv(out_csv, index=False)
    excel_path = os.path.splitext(out_csv)[0] + '.xlsx'
    df.to_excel(excel_path, index=False)
    print('Saved results to', out_csv, 'and', excel_path)
    return df

# -----------------------------
# If this script is run directly, run a small test (user can change paths)
# -----------------------------
if __name__ == '__main__':
    # Example usage: replace with your file paths
    edges_file = 'edges.txt'  # TAB separated file
    attr_file = 'attr.txt'    # optional

    # user parameters
    ks = [10, 20, 30, 40, 50]
    out_csv = 'experiment_compare.csv'

    # run experiments (this will be compute-heavy depending on graph size)
    df = run_experiments(edges_file, attr_file, remove_age_gt=None, ks=ks, out_csv=out_csv, p_ic=0.01, rr_theta=8000)

    print('Done')
