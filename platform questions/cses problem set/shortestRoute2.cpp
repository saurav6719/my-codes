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
void fw(vector<vector<int> > &graph, int n){
    for(int via = 1; via<=n ; via++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){      
                if(graph[i][via] != 1e15 and graph[via][j] != 1e15) graph[i][j] = min(graph[i][j] , graph[i][via] + graph[via][j]);
            }
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(graph[i][j] == 1e15) graph[i][j] = -1;
        }
    }
}
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int> > graph(n+5, vector<int> (n+5, 1e15));
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        graph[u][v] = min(graph[u][v] ,w);
        graph[v][u] = min(graph[u][v] ,w);
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
           if(i==j) graph[i][j] = 0;
        }
    }
    fw(graph, n);

    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<graph[a][b]<<endl;
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

