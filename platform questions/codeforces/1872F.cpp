/**
 *    author: Saurav
 *    created: 2024.10.21 22:01:43
 **/

/* includes and all */

#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)

#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
class DSU {
private:
    vector<int> parent; // parent[i] = parent of node i
    vector<int> rank;   // rank[i] = approximate depth of subtree rooted at i

public:
    // Constructor to initialize DSU with 'n' elements (0-based indexing)
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1); // Initialize all ranks to 1
        for (int i = 0; i < n; ++i)
            parent[i] = i; // Each element is its own parent initially
    }

    // Find the representative (root) of the set that contains 'x'
    // Implements path compression
    int find_set(int x) {
        if (parent[x] != x)
            parent[x] = find_set(parent[x]); // Path compression
        return parent[x];
    }

    // Union the sets that contain 'x' and 'y'
    // Implements union by rank
    bool union_sets(int x, int y) {
        int x_root = find_set(x);
        int y_root = find_set(y);
        if (x_root == y_root)
            return false; // Already in the same set

        // Union by rank: attach the smaller tree to the root of the larger tree
        if (rank[x_root] < rank[y_root]) {
            parent[x_root] = y_root;
        }
        else if (rank[x_root] > rank[y_root]) {
            parent[y_root] = x_root;
        }
        else {
            parent[y_root] = x_root;
            rank[x_root] += 1; // Only increase rank if both trees have same rank
        }
        return true; // Union was successful
    }

    // Optional: Get the number of disjoint sets
    int count_sets() {
        int cnt = 0;
        for (int i = 0; i < parent.size(); ++i)
            if (parent[i] == i)
                cnt++;
        return cnt;
    }

    // Optional: Check if two elements are in the same set
    bool same_set(int x, int y) {
        return find_set(x) == find_set(y);
    }
};


vector<int> kahnTopologicalSort(int V, const vector<vector<int>> &adj) {
    vector<int> in_degree(V, 0); // Initialize in-degree of all vertices to 0

    // Step 1: Calculate in-degree for each vertex
    for (int u = 0; u < V; u++) {
        for (auto &v : adj[u]) {
            in_degree[v]++;
        }
    }

    // Step 2: Initialize queue with all vertices having in-degree 0
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo_order; // To store the topological order

    // Step 3: Process the vertices
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);

        // Iterate through all the neighbors of dequeued vertex u
        for (auto &v : adj[u]) {
            in_degree[v]--; // Decrement in-degree by 1
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Step 4: Check if topological sort is possible (i.e., no cycles)
    if (topo_order.size() != V) {
        // Graph has at least one cycle
        return {}; // Return empty vector to indicate failure
    }

    return topo_order;
}
void solve(){
    int n;
    cin>>n;
    vector<int> afraid(n+1);
    vector<vector<int> > graph(n+1, vector<int> ());

    DSU d(n+1);

    set<int> cyclenodes;
    map<int,pp> parmini;


    vector<vector<int> > reversegraph(n+1, vector<int> ());



    for(int i = 1;i<=n; i++){
        cin>>afraid[i];
        graph[i].push_back(afraid[i]);
        reversegraph[afraid[i]].push_back(i);

        bool cycle = d.same_set(i, afraid[i]);
        if(cycle){
            cyclenodes.insert(i);
        }
        d.union_sets(i, afraid[i]);
    }
    vector<int> cost(n+1, 0);
    for(int i = 1; i<=n; i++){
        cin>>cost[i];
    }

    for(auto ele : cyclenodes){
        debug(ele);
    }


    for(auto ele : cyclenodes){
        int par = d.find_set(ele);
        parmini[par] ={1e15, -1};
        set<int> cycleaffectingnodes;
        int start = afraid[ele];
        int end = ele;
        while(start != end){
            cycleaffectingnodes.insert(start);
            start = graph[start][0];
        }
        cycleaffectingnodes.insert(end);

        for(auto ele2 :  cycleaffectingnodes){
            // cout<<"CYLEC"<<endl;
            debug(ele2);
            // cout<<"CYLEC"<<endl;

            if(cost[ele2] < parmini[par].first){
                parmini[par] = {cost[ele2] , ele2};
            } 
            
        }
    }


    for(auto ele : parmini){
        int xx = ele.first;
        debug(xx);
        debug(ele.second.first);
        debug(ele.second.second);
        
    }


    // printmap(parmini);

    print(cost);

    set<int> toremovenodes;


    for(auto ele : cyclenodes){
        int par = d.find_set(ele);
        int mini = parmini[par].second;
        toremovenodes.insert(mini);
    }

    for(auto ele : toremovenodes){
        debug(ele);
    }

    vector<vector<int>  >newgraph(n+1, vector<int> ());


    for(int i = 1; i<=n; i++){
        if(toremovenodes.count(i)) continue;
        newgraph[i].push_back(afraid[i]);
    }

    print2d(newgraph);

    vector<int> ans = kahnTopologicalSort(n+1, newgraph);


    for(auto ele : ans){
        if(ele == 0) continue;
        cout<<ele<<" ";
    }
    cout<<endl;




}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

