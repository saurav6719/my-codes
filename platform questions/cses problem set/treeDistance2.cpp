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
vector<int> sze;
int subtreeSize(vector<vector<int> > &tree, int src, int par){
    if(tree[src].size() == 1 and src!=1) return sze[src] = 1;
    int ans = 1;
    for(int child : tree[src]){
        if(child == par) continue;
        ans += subtreeSize(tree, child, src);
    }
    return sze[src] = ans;
}

vector<int> distancee;
int f(vector<vector<int> > &tree, int src, int par){
    if(tree[src].size() == 1 and src!=1){
        return distancee[src] = 0;
    }
    int ans = 0;
    for(int child : tree[src]){
        if(child == par) continue;
        ans += f(tree, child, src);
        ans += sze[child];
    }

    return distancee[src] = ans;
}

vector<int> final;
void dfs(vector<vector<int> > &tree, int src, int par , vector<int> &final){
    for(int child : tree[src]){
        if(child == par) continue;
        final[child] = final[src] + distancee[child] - (distancee[child] + sze[child]) + sze[1] - sze[child];
        dfs(tree, child, src, final); 
    }
    return ;
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int> > tree(n+1, vector<int> ());
    for(int i = 0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    sze.resize(n+5);
    distancee.resize(n+5);
    final.resize(n+5);

    int xx = subtreeSize(tree, 1, 0);
    int yy = f(tree, 1, 0);

    final[1] = distancee[1];
    debug(final[1]);
    dfs(tree, 1, 0, final);

    for(int i = 1 ; i<=n; i++){
        cout<<final[i]<<" ";
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

