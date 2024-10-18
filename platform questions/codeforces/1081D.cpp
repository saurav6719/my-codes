/**
 *    author: Saurav
 *    created: 2024.10.18 21:54:15
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
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> special(k);
    for(auto &x : special) cin>>x;

    vector<vector<pp> > graph(n+1, vector<pp>());

    int start = special[0];
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    vector<int> dist(n+1, LLONG_MAX);

    priority_queue<pp, vector<pp>, greater<pp>> pq;

    dist[start] = 0;

    pq.push({0,start});

    while(!pq.empty()){
        auto current = pq.top();
        pq.pop();

        int node = current.second;
        int weight = current.first;

        if(weight > dist[node]) continue;

        for(auto x : graph[node]){
            int next_node = x.first;
            int next_weight = x.second;

            if(dist[next_node] > max(weight , next_weight)){
                dist[next_node] = max(weight , next_weight);
                pq.push({dist[next_node], next_node});
            }
        }
    }

    print(dist);


    int farthest = 0;
    int farthestidx = -1;

    for(int i = 1; i<k;i++){
        if(dist[special[i]] > farthest){
            farthest = dist[special[i]];
            farthestidx = special[i];
        }
    }

    for(int i= 0; i<k; i++){
        cout<<farthest<<" ";
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

