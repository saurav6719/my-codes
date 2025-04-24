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
struct route{
    int cost;
    int dest;
    int used;
};

struct CompareRoute {
    bool operator()(route const& r1, route const& r2) {
        return r1.cost > r2.cost; // Min-heap based on cost
    }
};

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pp> > graph(n+5, vector<pp> ());
    for(int i = 0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }
    vector<int> discount(n+5, 1e15);
    vector<int> full(n+5, 1e15);
    discount[1] = 0;
    full[1] = 0;
    priority_queue<route , vector<route> , CompareRoute> pq;
    pq.push({0,1,0});
    while(!pq.empty()){
        route r1 = pq.top();
        pq.pop();
        if(r1.used == 1){
            if(discount[r1.dest] < r1.cost) continue;
        }
        else{
            if(full[r1.dest] < r1.cost) continue;
        }
        for(auto neigh : graph[r1.dest]){
            if(r1.used == 0){
                if(discount[neigh.first] > r1.cost + neigh.second/2){
                    discount[neigh.first] = r1.cost + neigh.second / 2;
                    pq.push({discount[neigh.first],neigh.first,1});
                }
                if(full[neigh.first] > r1.cost + neigh.second){
                    full[neigh.first] = r1.cost + neigh.second ;
                    pq.push({full[neigh.first],neigh.first,0});
                }
            }
            else{
                if(discount[neigh.first] > r1.cost + neigh.second){
                    discount[neigh.first] = r1.cost + neigh.second;
                    pq.push({discount[neigh.first],neigh.first,1});
                }
            }
        }
    }

    cout<<discount[n];
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

