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
vector<vector<int> > dp1;

vector<vector<int> > dp2;
void dfs1(vector<vector<int> > &tree, int i, int par, int k){
    for(auto child : tree[i]){
        if(child != par){
            dfs1(tree, child, i, k);
        }
    }

    dp1[i][0] = 1;

    for(int j = 1; j<=k; j++){
        dp1[i][j] = 0;
        for(auto child : tree[i]){
            if(child != par) dp1[i][j] += dp1[child][j-1];
        }
    }
}


void dfs2(vector<vector<int> > &tree, int i, int par, int k){
    for(int j = 0; j<=k; j++){
        dp2[i][j] = dp1[i][j];
    }

    if(par != 0){
        dp2[i][1] += dp2[par][0];
        for(int j = 2; j<=k; j++){
            dp2[i][j] += dp2[par][j-1];
            dp2[i][j] -= dp1[i][j-2];
        }
    }



    for(auto child : tree[i]){
        if(child != par) dfs2(tree, child, i, k);
    }
}

void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<vector<int> > tree(n+5, vector<int> ());

    for(int i= 0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dp1.resize(n+5, vector<int> (k+5, 0));
    dp2.resize(n+5, vector<int> (k+5, 0));

    dfs1(tree, 1, 0, k);
    dfs2(tree, 1, 0, k);
    int ans = 0;

    for(int i = 1; i<=n; i++){
        ans += dp2[i][k];
    }

    cout<<ans/2;

    

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

