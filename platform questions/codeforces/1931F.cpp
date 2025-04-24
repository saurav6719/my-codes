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
bool dfs(int node, vector<int> &visited, vector<vector<int> > &graph, int par, vector<int> &parent){
    // debug(node);
    visited[node] = 1;
    parent[node] = par;

    for(auto neigh : graph[node]){
        if(visited[neigh] == 1){
            return true;
        }
        if(visited[neigh] == 0){
            bool xx = dfs(neigh, visited, graph, node, parent);
            if(xx) return true;
        }
    }
    visited[node] = 2;
    return false;
}
void solve(){
    int n;
    int k;
    cin>>n>>k;
    vector<vector<int> > graph(n+5, vector<int>());
    map<int,set<int> > mp;

    for(int i = 0; i<k; i++){
        vector<int> v;

        bool first = false;
        for(int j = 0; j<n; j++){
            int ele;
            cin>>ele;
            if(!first){
                first = true;
                continue;
            }
            v.push_back(ele);
            // debug(ele);
            
        }
        print(v);

        if(v.empty())continue;

        for(int l = 0; l<v.size() - 1; l++){
            int u = v[l];
            int vv = v[l+1];

            if(mp[u].count(vv)) continue;
            graph[u].push_back(vv);
            mp[u].insert(vv);
        }
    }

    print2d(graph);


    vector<int > visited(n+5, 0);
    vector<int> parent(n+5, -1);

    for(int i = 1; i<=n; i++){
        if(visited[i] == 0){
            bool xx = dfs(i, visited, graph, 0, parent);
            if(xx){
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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

