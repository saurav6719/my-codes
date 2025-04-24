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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > graph(n+5, vector<int> ());
    for(int i = 0; i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visited(n+5, -1);
    vector<int> parent(n+5, -1);

    queue<int> qu;

    qu.push(1);
    visited[1] = 1;
    parent[1] = 1;
    while(!qu.empty()){
        int ele = qu.front();
        qu.pop();
        for(auto neigh : graph[ele]){
            if(visited[neigh] == -1){
                qu.push(neigh);
                parent[neigh] = ele;
                visited[neigh] = 1;
            }
        }
    }

    if(visited[n] == -1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    vector<int> ans;
    ans.push_back(n);
    int ele = n;

    while(true){
        ans.push_back(parent[ele]);
        if(parent[ele] == 1) break;
        ele = parent[ele];
    }

    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(auto element : ans){
        cout<<element<<" ";
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

