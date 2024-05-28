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
vector<vector<int> > visited;
string ans = "";
void dfs(vector<vector<char> > &graph, int n, int m, int sr, int sc, string curr){
    
    if(graph[sr][sc] == 'B'){
        if(ans.size() > 0){
            if(curr.size() <= ans.size()){
                ans = curr;
            }
        }  
        else ans = curr;
        return ;
    }
    visited[sr][sc] = true;


    if(sr+1 < n and visited[sr+1][sc] == false and ((graph[sr+1][sc] == '.') or (graph[sr+1][sc] == 'B'))){
        dfs(graph, n, m,  sr+1, sc, curr + 'D');

    }

    if(sc+1 < m and visited[sr][sc+1] == false and ((graph[sr][sc+1] == '.')  or (graph[sr][sc+1] == 'B'))){
        dfs(graph, n, m,  sr, sc+1, curr + 'R');
        
    }

    if(sr-1 >= 0 and visited[sr-1][sc] == false and ((graph[sr-1][sc] == '.') or (graph[sr-1][sc] == 'B'))){
        dfs(graph, n, m,  sr-1, sc, curr + 'U');
        
    }

    if(sc-1 >= 0 and visited[sr][sc-1] == false and ((graph[sr][sc-1] == '.')  or (graph[sr][sc-1] == 'B'))){
        dfs(graph, n, m,  sr, sc-1, curr + 'L');
        
    }

    visited[sr][sc] = false;
    //curr.pop_back();


    
}
void solve(){
    
    cin>>n>>m;
    vector<vector<char> > input(n, vector<char> (m));
    for(int i = 0; i<n; i++){
        for(int j = 0 ; j<m; j++){
            cin>>input[i][j];
        }
    }

    visited.resize(n+5, vector<int> (m+5, false));
    int sr;
    int sc;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(input[i][j] == 'A'){
                sr = i;
                sc = j;
                break;
            }
        }
    }
    dfs(input,n,m,sr,sc,"");
    if(ans.size() > 0){
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }
    else cout<<"NO"<<endl;

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

