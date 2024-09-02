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
                            cout << v[i][j].first << " "<<v[i][j].second<<" "; \
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

bool dfs(vector<set<int> > &coordinates, int node, vector<vector<pp> > &graph, vector<int> &visited, int curr){
    visited[node] = 1;
    coordinates[node].insert(curr);
    if(coordinates[node].size() > 1){
        return false;
    }
    for(auto ele : graph[node]){
        if(visited[ele.first] == 1){
            coordinates[ele.first].insert(curr + ele.second);
            if(coordinates[node].size() > 1){
                return false;
            }
            continue;
        }
        bool xx = dfs(coordinates, ele.first, graph, visited, curr+ele.second);
        if(!xx) {
            debug(node);
            debug(ele.first);
            return false;
        }
    }
    return true;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pp> > graph(n+5, vector<pp> ());


    for(int i= 0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,-w});
    }

    vector<int> visited(n+5, 0);
    vector<set<int> > coordinates(n+5, set<int> ());

    print2d(graph);
    // dfs(coordinates, 1, graph, visited, 0);

    for(int i = 1; i<=n; i++){
        if(visited[i] == 0){
            bool xx = dfs(coordinates, i, graph, visited, 0);
            if(!xx){
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    cout<<"YES"<<endl;

    

    




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
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

