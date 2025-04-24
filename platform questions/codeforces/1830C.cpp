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
int ans;
void dfs(vector<vector<pair<int,int> > > &graph, set<int> &visited,int it, int idx, int par){
    ans = max(ans, it);
    //debug(ans);
    for(auto ele : graph[par]){
        int val = ele.first;
        //debug(val);
        if(visited.count(val)) continue;
        visited.insert(val);
        if(val == par) continue;
        int index = ele.second;
        //debug(index);
        if(index > idx) dfs(graph,visited, it,index, val);
        else dfs(graph,visited, it+1,index, val);
    }
}
void solve(){
    int n;
    cin>>n;
    vector<vector<pair<int,int> > > graph(n+5, vector<pair<int,int> > ());
    ans =0;
    for(int i = 0; i<n-1; i++){
        int u;
        cin>>u;
        int v;
        cin>>v;
        graph[u].push_back({v,i});
        graph[v].push_back({u,i});
    }
    set<int> visited;
    visited.insert(1);
    dfs(graph,visited,  0, n, 1);
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

