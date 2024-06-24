#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;






void findBridgesAndSubtreeSizes(int node, int parent, vector<pair<int, int>>& bridges, vector<vector<int> > & graph, vector<bool> &visited, vector<int> &initial, vector<int> &low_time, vector<int> &subtree_size, int time_counter) {
    visited[node] = true;
    initial[node] = low_time[node] = ++time_counter;
    subtree_size[node] = 1;

    for (int neighbor : graph[node]) {
        if (neighbor == parent) continue;

        if (!visited[neighbor]) {
            findBridgesAndSubtreeSizes(neighbor, node, bridges, graph, visited, initial, low_time, subtree_size, time_counter);
            subtree_size[node] += subtree_size[neighbor];
            low_time[node] = min(low_time[node], low_time[neighbor]);

            if (low_time[neighbor] > initial[node]) {
                bridges.push_back({node, neighbor});
            }
        } else {
            low_time[node] = min(low_time[node], initial[neighbor]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > graph(n+5);
    vector<pair<int, int>> edges(m);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges[i] = {u, v};
    }
    vector<int> initial(n+5);
    vector<int> low_time(n+5);
    vector<int> subtree_size(n+5);
    vector<bool> visited(n+5, false);
    vector<pair<int, int>> bridges;
    int time_counter = 0;
    findBridgesAndSubtreeSizes(1, -1, bridges, graph, visited, initial, low_time, subtree_size, time_counter);
    int total_pairs = n * (n - 1) / 2;
    int min_connected_pairs = total_pairs;

    for (auto bridge : bridges) {
        int u = bridge.first;
        int v = bridge.second;

        if (subtree_size[u] < subtree_size[v]) swap(u, v);

        int size1 = subtree_size[v];
        int size2 = n - size1;

        int connected_pairs_after_removal = (size1 * (size1 - 1) / 2) + (size2 * (size2 - 1) / 2);
        min_connected_pairs = min(min_connected_pairs, connected_pairs_after_removal);
    }

    cout << min_connected_pairs << endl;
    return 0;
}
