/**
 *    author: Saurav
 *    created: 2024.11.07 01:38:37
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

void dijkastra(vector<vector<int> > &graph, int n, int start , vector<int> &dist){
    vector<bool> vis(n+1, false);
    dist[start] = 0;
    priority_queue<pp, vector<pp>, greater<pp> > pq;
    pq.push({0, start});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if(vis[u]) continue ;
        vis[u] = true;

        for(auto v : graph[u]){
            int w = 1;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

struct special{
    int vertex;
    int distfrom1;
    int distfromn;

    bool operator < (const special &b) const{
        return (distfrom1 - distfromn) < (b.distfrom1 - b.distfromn);
    }
};
void solve(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    int k;
    cin>>k;

    vector<int> specialvertices(k);
    for(auto &x : specialvertices){
        cin>>x;
    }

    vector<vector<int> > graph(n+1, vector<int> ());

    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> distfrom1(n+1, 1e18);
    vector<int> distfromn(n+1, 1e18);
    dijkastra(graph, n, 1, distfrom1);
    dijkastra(graph, n, n, distfromn);

    vector<special> specialnodes;

    for(auto x : specialvertices){
        specialnodes.push_back({x, distfrom1[x], distfromn[x]});
    }

    sort(specialnodes.begin(), specialnodes.end());


    vector<int> maxsuffix(k);
    maxsuffix[k-1] = specialnodes[k-1].distfromn;
    for(int i = k-2; i>=0; i--){
        maxsuffix[i] = max(maxsuffix[i+1], specialnodes[i].distfromn);
    }

    int maxi = -1;

    for(int i = 0; i<k-1; i++){
        maxi = max(maxi, specialnodes[i].distfrom1 + maxsuffix[i+1] + 1);
    }

    cout<<min(maxi , distfrom1[n])<<endl;
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

