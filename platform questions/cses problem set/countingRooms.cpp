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
int n,m;
vector<vector<bool> >visited;
void dfs(vector<vector<char> > &graph, int sr, int sc, int n, int  m){
    visited[sr][sc] = true;
    if(sr+1 < n and visited[sr+1][sc] == false and graph[sr+1][sc] == '.'){
        dfs(graph, sr+1, sc, n , m);
    }

    if(sr-1 >= 0 and visited[sr-1][sc] == false and graph[sr-1][sc] == '.'){
        dfs(graph, sr-1, sc, n , m);
    }

    if(sc-1 >= 0 and visited[sr][sc-1] == false and graph[sr][sc-1] == '.'){
        dfs(graph, sr, sc-1, n , m);
    }

    if(sc+1 < m and visited[sr][sc+1] == false and graph[sr][sc+1] == '.'){
        dfs(graph, sr, sc+1, n , m);
    }
}

void solve(){
    cin>>n>>m;
    vector<vector<char> > graph(n, vector<char> (m));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>graph[i][j];
        }
    }
    visited.resize(n+5, vector<bool> (m+5, false));
    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(graph[i][j] == '.' and visited[i][j] == false){
                dfs(graph,i,j,n,m);
                ans++;
            }
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

