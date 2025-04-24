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

bool dfs(vector<vector<int> > &graph , int i, vector<int> &visiteddfs,  vector<int> &ans, int curr, bool poss){
    
    ans[i] = curr;
    visiteddfs[i] = 1;
    for(auto neigh : graph[i]){
        if(ans[neigh] == curr){
            poss = false;
            return false;
        }
        if(visiteddfs[neigh] == -1){
            bool res = dfs(graph, neigh, visiteddfs , ans, (curr == 1 ? 2 : 1), poss);
            if(res == false) return false;
        }
    }
    return true;
}
void solve(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int> > graph(n +5, vector<int> ());
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visiteddfs(n+5, -1);
    vector<int> ans(n+5, -1);
    bool poss = true;

    for(int i = 1; i<=n; i++){
        if(visiteddfs[i] == -1){
            poss = dfs(graph, i, visiteddfs, ans, 1, poss);
            if(!poss){
                cout<<"IMPOSSIBLE"<<endl;
                return;  
            }

        }
    }

    

    // queue<int> qu;
    // qu.push(1);
    // vector<int> visitedbfs(n+5, -1);
    // visitedbfs[1] = 1;
    // while(!qu.empty()){
    //     int curr = qu.front();
    //     qu.pop();

    //     for(auto neigh : graph[curr]){
    //         if(ans[neigh] == ans[curr]){
    //             cout<<"IMPOSSIBLE"<<endl;
    //             return;
    //         }

    //         if(visitedbfs[neigh] == -1){
    //             qu.push(neigh);
    //             visitedbfs[neigh] = 1;
    //         }
    //     }
    // }

    for(int i = 1; i<=n; i++){
        cout<<ans[i]<<" ";
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

