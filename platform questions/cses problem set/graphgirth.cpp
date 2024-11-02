/**
 *    author: Saurav
 *    created: 2024.11.01 00:02:24
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
int ans = 1e9;
void bfs(vector<vector<int> > &graph, int n){
    for(int i = 1; i<=n; i++){
        vector<int> dist(n+1,-1);
        vector<int> parent(n+1,-1);
        dist[i] = 0;
        parent[i] = 0;
        // visited[i] = 1;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto neigh : graph[node]){
                if(neigh == parent[node]) continue; 
                if(dist[neigh] == -1){
                    // visited[neigh] = 1;
                    dist[neigh] = dist[node] + 1;
                    parent[neigh] = node;
                    q.push(neigh);
                }
                else{
                    ans = min(ans,dist[node] + dist[neigh] + 1);
                }
            }
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1,vector<int>());
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(graph,n);
    if(ans == 1e9){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
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

