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
void dijakastr(vector<vector<pp> > &graph, vector<int> &dist, bool two, int n){
    priority_queue<pp, vector<pp>, greater<pp> > pq;
    pq.push({0, 1});

    dist[1] = 0;

    if(two){
        for(int i = 2; i<=n; i++){
            pq.push({dist[i], i});
        }
    }
    while(!pq.empty()){
        auto ff = pq.top();
        pq.pop();

        int currweight = ff.first;
        int currnode = ff.second;

        if(dist[currnode] < currweight) continue;

        for(auto neigh : graph[currnode]){
            if(currweight + neigh.second < dist[neigh.first]){
                dist[neigh.first] = currweight + neigh.second;
                pq.push({currweight + neigh.second , neigh.first});
            }
        }
    }
}

void solve(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<vector<pp> > graph( n+5, vector<pp> ());

    vector<vector<pp> > graph2( n+5, vector<pp> ());

    for(int i = 0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph2[v].push_back({u,w});
    }

    

    vector<int> dist(n+5, 1e15);
    dijakastr(graph, dist, false, n);
    print(dist);

    dijakastr(graph2, dist, true, n);
    print(dist);

    for(int i = 2; i<=n; i++){
        int xx = dist[i];
        if(xx>1e14) xx = -1;
        cout<<xx<<" ";
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

