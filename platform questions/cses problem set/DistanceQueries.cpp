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

vector<vector<int> > powpar;
vector<int> level;

void blf(vector<int> &par, int n){
    for(int i = 1; i<=n; i++){
        powpar[i].push_back(par[i]);
    }

    for(int j = 1; j<20; j++){
        for(int i = 1; i<=n; i++){
            if(powpar[i][j-1] == -1) powpar[i].push_back(-1);
            else{
                int ele = powpar[i][j-1];
                powpar[i].push_back(powpar[ele][j-1]);
            }
        }
    }
}


int lft(int node , int k){
    for(int i = 19; i>=0; i--){
        if(node == -1) return -1;
        if((k&(1<<i))){
            node = powpar[node][i];
            k-=(1<<i);
        }
    }
    return node;
}


void dfs(vector<vector<int> > &tree , int src, vector<int> &visited){
    visited[src] = 1;
    for(auto child : tree[src]){
        if(visited[child] == -1){
            level[child] = level[src]+1;
            dfs(tree, child , visited);
        }
    }
}

int lca(int u, int v){
    if(level[v]>level[u]) swap(u,v);
    u = lft(u, level[u] - level[v]);
    if(u==v) return v;

    for(int i = 19; i >= 0; i--) {
        if(powpar[u][i] != powpar[v][i]) {
            u = powpar[u][i];
            v = powpar[v][i];
        }
    }
    return powpar[u][0];

}

void findingParent(vector<vector<int> > &tree, int src, int par, vector<int> &visited, vector<int> &parent){
    visited[src] = 1;
    for(auto child : tree[src]){
        if(visited[child] == -1){
            parent[child] = src;
            findingParent(tree, child, src, visited, parent);
        }
    }
}




void solve(){
    int n;
    cin>>n;
    int q;
    cin>>q;
    vector<vector<int> > tree(n+5, vector<int> ());
    vector<int> par(n+5);
    par[1] = -1;
    for(int i = 0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int> visited2(n+5, -1);
    findingParent(tree, 1, -1, visited2, par);

    print(par);
    powpar.resize(n+5, vector<int> ());
    blf(par, n);

    level.resize(n+5);
    level[1] = 0;
    vector<int> visited(n+5, -1);
    dfs(tree, 1, visited);
    print(level);
    while(q--){
        int u, v;
        cin>>u>>v;
        int ff = lca(u,v);wwww
        cout<<level[u] - level[ff] + level[v] - level[ff]<<endl;

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

