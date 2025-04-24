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

void topoSortWithWeights(int n, vector<vector<pair<int, int>>>& adj, vector<int> &ans) {
    vector<int> indegree(n, 0);  // Indegree array and result array
    queue<int> q;

    // Calculate indegree of each vertex
    for (int u = 0; u < n; ++u) {
        for (auto& [v, w] : adj[u]) {
            indegree[v]++;
        }
    }

    set<int> st;
    int start = -1;

    // Initialize vertices with indegree 0 and set their ans to 0
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            debug(i);
            q.push(i);
            start = i;
            ans[i] = 0;  // Assign 0 to vertices with indegree 0
            break;
        }
    }

    // Perform topological sort and update ans array
    while (!q.empty()) {
        int u = q.front();
        if(st.count(u)) {
            q.pop();
            continue;
        }

        st.insert(u);
        q.pop();

        for (auto& [v, w] : adj[u]) {

            indegree[v]--;
            debug(v);
            // Update ans for vertex v based on the edge weight 
            ans[v] = ans[u] + w;  // Update with the minimum possible value
            debug(ans[u]);
            debug(ans[v]);

            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    for(int i = 0; i<n; i++){
        if(ans[i] == 0 and i!= start){
            for(auto &[v,w] : adj[i]){
                if(ans[v] == 0 and v!= start) continue;
                ans[i] = ans[v]  - w;
            }
        }
    }
    
}

void dfs(vector<vector<pp> > &graph, vector<int> &ans, vector<int> &visited, int node){
    visited[node] = 1;

    for(auto child : graph[node]){
        if(visited[child.first] == 0){
            ans[child.first] = ans[node] + child.second;
            dfs(graph, ans, visited, child.first);
        }
    }

}

void solve(){
    int n,m;
    cin>>  n>>m;

    vector<vector<pp> > graph(n+5, vector<pp> ());


    for(int i = 1; i<=m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        graph[u].push_back({v,w});
        graph[v].push_back({u,-w});
    }



    vector<int> visited(n+5, 0);

    vector<int> ans(n+5, 0);

    
    // topoSortWithWeights(n, graph,ans);

    for(int i = 0 ; i<n; i++){
        if(visited[i] ==0 ){
            dfs(graph, ans, visited, i);
        }
    }

    print(ans);

    for(int i = 0; i<n; i++){
        cout<<ans[i]<<" ";
    }
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

