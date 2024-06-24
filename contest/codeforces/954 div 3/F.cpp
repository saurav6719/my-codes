/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Saurav     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \___/   /
           \  -----  /
             \_____/
  
  Happy coding! 
*/

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
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */

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

void solve(){
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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

