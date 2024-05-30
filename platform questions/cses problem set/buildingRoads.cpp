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
int m;
vector<int> visited;
void dfs(vector<vector<int> > &graph , int n, int m , int src){
    visited[src] = 1;
    for(auto neigh : graph[src]){
        if(visited[neigh] == -1){
            dfs(graph,n,m, neigh);
        }
    }
}
void solve(){
    
    cin>>n;
    
    cin>>m;
    vector<vector<int> >graph(n+5, vector<int> ());
    for(int i = 0; i<m; i++){
        int u;
        cin>>u;
        int v;
        cin>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    visited.resize(n+5,-1);
    int ans = 0;
    vector<int> res;
    

    for(int i =1 ; i<=n; i++){
        if(visited[i] == -1){

            ans ++;
            res.push_back(i);
            dfs(graph,n,m,i);
        }
        else continue;
    }

    cout<<ans-1<<endl;
    for(int i = 0; i<res.size()- 1; i++){
        cout<<res[i]<<" "<<res[i+1];
        cout<<endl;
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

