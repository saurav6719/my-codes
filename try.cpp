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

int dfs(int node, vector<int> adj[], vector<int> &dp){
    if(adj[node].size() == 0) return 0;

    for(auto &child : adj[node]){
        if(dp[child] == -1){
            dp[node] = max(dp[node], 1 + dfs(child, adj, dp));
        }
        else{
            dp[node] = max(dp[node], 1 + dp[child]);
        }
    }

    return dp[node];
}

/* write core logic here */
void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> edges;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<int> adj[n + 1];
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
    }

    for(auto v : adj){
        print(v);
    }

    vector<int> dp(n + 1, -1);
    int curr = 1;
    
    for(int i = 1; i <= n; i++){
        if(dp[i] == -1){
            int temp = dfs(i, adj, dp);
        }
    }

    // for(int i = 1; i <= n; i++){
    //     cout << dp[i] << " ";
    // }cout << endl;

    cout << *max_element(dp.begin(), dp.end()) << endl;
}   
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t = 1;
    // cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
    
    return 0;
}
