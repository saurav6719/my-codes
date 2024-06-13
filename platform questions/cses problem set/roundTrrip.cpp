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
using namespace std;

/* write core logic here */
int final = -1;
int initial = -1;
bool dfs(vector<vector<int> > &graph, vector<int> &visited, int i, int parent, vector<int> &v, vector<int> &par){

    visited[i] = 1;
    par[i] = parent;
    for(auto neigh : graph[i]){
        if(visited[neigh] == 1 and neigh != par[i]){
            final = neigh;
            initial = i; 
            return true;
        }
        if(visited[neigh] == -1){
            bool res = dfs(graph, visited, neigh, i, v, par);
            if(res == true) {
                return true;
            }
        }
    }

    return false;
}
void solve(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int> > graph(n+5, vector<int> ());

    while(m--){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visited(n+5, -1);
    vector<int> v;

    vector<int> parent(n+5, -1);

    bool find = false;
    for(int i = 1; i<=n; i++){
        if(visited[i] == -1){
            find = dfs(graph, visited, i, 0, v, parent);
            if(find == true) break;
        }

    }

    
    

    if(!find){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    v.push_back(final);

    int i = initial;

    while(i!= final){
        v.push_back(i);
        i= parent[i];
    }

    v.push_back(final);

    cout<<v.size()<<endl;

    for(auto ele: v){
        cout<<ele<<" ";
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

