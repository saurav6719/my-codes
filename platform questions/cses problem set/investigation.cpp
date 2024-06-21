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
struct cmp{
    bool operator() (pp &a, pp &b){
        return (a.second) > (b.second);
    }
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pp> > graph(n+5, vector<pp> ());
    vector<int> cost(n+5, 1e15);
    vector<int> routes(n+5, 0);
    vector<int> minfl(n+5, 0);
    vector<int> maxfl(n+5, 0);
    for(int i = 0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }

    priority_queue<pp, vector<pp>, cmp> pq;
    pq.push({1,0});
    routes[1] = 1;
    minfl[1] = 0;
    maxfl[1] = 0;
    cost[1] = 0;
    while(!pq.empty()){
        pp ff = pq.top();
        pq.pop();
        int u = ff.first;
        debug(u);
        int w = ff.second;
        if(cost[u] < w) continue;
        for(auto neigh : graph[u]){

            if(cost[neigh.first] == cost[u] + neigh.second){
                cost[neigh.first] = cost[u] + neigh.second;
                routes[neigh.first] += routes[u];
                routes[neigh.first] %= mod;
                minfl[neigh.first] = min(minfl[neigh.first] , minfl[u] + 1);
                maxfl[neigh.first] = max(maxfl[neigh.first] , maxfl[u] + 1);
            }
            
            if(cost[neigh.first] > cost[u] + neigh.second){
                cost[neigh.first] = cost[u] + neigh.second;
                routes[neigh.first] = routes[u];
                routes[neigh.first] %= mod;
                minfl[neigh.first] = minfl[u] + 1;
                maxfl[neigh.first] = maxfl[u] + 1;
                pq.push({neigh.first , cost[u] + neigh.second});
            }

            
        }
    }

    cout<<cost[n]<<" "<<routes[n]<<" "<<minfl[n]<<" "<<maxfl[n];

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

