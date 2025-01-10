/**
 *    author: Saurav
 *    created: 2025.01.11 02:52:14
 **/

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
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)

#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
void dijkastra(vector<vector<pp> > &graph, vector<int> &cost, int n){
    priority_queue<pp, vector<pp>, greater<pp> > pq;

    for(int i =1; i<=n; i++){
        pq.push({cost[i],i});
    }

    while(!pq.empty()){
        pp top = pq.top();
        pq.pop();
        int currnode = top.second;
        int currdist = top.first;

        if(cost[currnode] < currdist){
            continue;
        }

        for(auto x : graph[currnode]){
            int v = x.first;
            int w = x.second;
            if(cost[v] > currdist + 2*w){
                cost[v] = currdist + 2*w;
                pq.push({cost[v],v});
            }
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pp> > graph(n+1);
    for(int i =0 ; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    vector<int> cost(n+1);
    for(int i = 1; i<=n; i++){
        cin>>cost[i];
    }

    dijkastra(graph,cost,n);

    for(int i = 1; i<=n; i++){
        cout<<cost[i]<<" ";
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

