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
#define pp pair<int,int> 
using namespace std;


/* write core logic here */
void solve(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<pair<int,int> > > graph(n+1, vector<pair<int, int> > ());
    for(int i = 0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }

    priority_queue<pp, vector<pp> , greater<pp> > pq;
    pq.push({0,1});
    vector<int> ans(n+5, LLONG_MAX);
    ans[1] = 0;

    while(!pq.empty()){
        pp ff = pq.top();
        pq.pop();
        if(ff.first > ans[ff.second]) continue;
        for(auto neigh : graph[ff.second]){
            if(ans[neigh.first] > ans[ff.second] + neigh.second){
                ans[neigh.first] = ans[ff.second] + neigh.second;
                pq.push({ans[neigh.first], neigh.first});
            }
        }
    }


    for(int i = 1;i<=n; i++){
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}