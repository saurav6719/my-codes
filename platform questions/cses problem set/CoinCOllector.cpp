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
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void union_sets(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        
        if (root_u != root_v) {
            if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            } else if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            } else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
        }
    }
};

void dfs1(int u, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& Stack) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs1(v, graph, visited, Stack);
        }
    }
    Stack.push(u);
}

void dfs2(int u, vector<vector<int>>& transpose_graph, vector<bool>& visited, vector<int>& component) {
    visited[u] = true;
    component.push_back(u);
    for (int v : transpose_graph[u]) {
        if (!visited[v]) {
            dfs2(v, transpose_graph, visited, component);
        }
    }
}

void kosaraju(int n, vector<vector<int>>& graph, DSU& dsu) {
    stack<int> Stack;
    vector<bool> visited(n+1, false);

    // Step 1: Fill nodes in stack according to their finishing times
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs1(i, graph, visited, Stack);
        }
    }

    // Step 2: Create the transpose of the graph
    vector<vector<int>> transpose_graph(n+1);
    for (int u = 1; u <= n; u++) {
        for (int v : graph[u]) {
            transpose_graph[v].push_back(u);
        }
    }

    // Step 3: Process all vertices in order defined by Stack
    fill(visited.begin(), visited.end(), false);
    
    while (!Stack.empty()) {
        int u = Stack.top();
        Stack.pop();

        if (!visited[u]) {
            vector<int> component;
            dfs2(u, transpose_graph, visited, component);

            // Union all nodes in the same SCC
            for (size_t i = 1; i < component.size(); i++) {
                dsu.union_sets(component[0], component[i]);
            }
        }
    }
}

vector<int> dp;

int f(vector<vector<int> > &newgraph, int node, vector<int> &newvalues, vector<int> &visited){

    if(dp[node] != -1) return dp[node];
    int ans = newvalues[node];
    dp[node] = ans;
    int curr = 0;
    for(auto child : newgraph[node]){
        
        curr = max(curr , f(newgraph, child, newvalues, visited));
        
    }

    ans += curr;
    return dp[node] = ans;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> coins(n+5);
    for(int i = 1; i<=n; i++){
        cin>>coins[i];
    }

    vector<vector<int> > graph(n+5, vector<int> () );
    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }

    DSU dsu(n);
    kosaraju(n, graph, dsu);

    vector<int> sumval(n+5);
    

    for(int i = 1; i<=n; i++){
        int xx = dsu.find(i);
        sumval[xx] += coins[i];
    }

    print(sumval);

    vector<vector<int> > newgraph(n+5, vector<int> ());
    debug(dsu.find(8));

    for(int i = 1; i<=n; i++){
        for(auto ele : graph[i]){
            int xx = dsu.find(i);
            int yy = dsu.find(ele);
            if(xx == yy) continue;
            newgraph[xx].push_back(yy);
        }
    }

    print2d(newgraph);

    set<int> newnodes;

    for(int i = 1; i<=n; i++){
        newnodes.insert(dsu.find(i));
    }

    // for(auto ele : newnodes){
    //     cout<<ele<<" ";
    // }

    dp.resize(n+5, -1);

    vector<int> visited(n+5, 0);
    int ans = INT_MIN;

    for(auto ele : newnodes){
        if(visited[ele] == 0){
            ans = max(ans , f(newgraph, ele, sumval, visited));
            debug(ele);
            debug(ans);
        }
    }

    cout<<ans<<endl;

    

    







}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

