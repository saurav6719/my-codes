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
int n;
vector<int> visited;
vector<int> ans;
vector<vector<int> > graph;


int dfs(int root){
    int cnt = 1;
    visited[root] = 1;
    for(auto neigh : graph[root]){
        if(visited[neigh] == -1) cnt += dfs(neigh);
    }
    return ans[root] = cnt;
}
void solve(){
    cin>>n;
    visited.resize(n+5, -1);
    ans.resize(n+5);
    graph.resize(n+5, vector<int> ());
    for(int i = 0; i<n-1; i++){
        int u;
        cin>>u;
        int v;
        cin>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if(n&1){
        cout<<-1<<endl;
        return;
    }

    dfs(1);

    int cnt = 0;
    for(int i = 1; i<=n; i++){
        if(ans[i] % 2 == 0){
            cnt++;
        }
    }

    cout<<cnt-1<<endl;





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

