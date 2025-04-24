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
#define pp pair<int,int> 
using namespace std;

/* write core logic here */
int dp[200005][2];

void f(vector<vector<int>> &tree, int src, int par){
    if(tree[src].size() == 1 && src != 1){ // src is leaf
        dp[src][0] = 0;
        dp[src][1] = 0;
        return;
    }

    for(int child : tree[src]){
        if(child != par){
            f(tree, child, src);
        }
    }

    vector<int> prf;
    vector<int> suf;

    for(int child : tree[src]){
        if(child == par) continue;
        prf.push_back(max(dp[child][0], dp[child][1]));
        suf.push_back(max(dp[child][0], dp[child][1]));
    }

    for(int i = 1; i < prf.size(); i++){
        prf[i] += prf[i-1];
    }
    for(int i = suf.size() - 2; i >= 0; i--){
        suf[i] += suf[i+1];
    }

    dp[src][0] = suf.empty() ? 0 : suf[0];
    int child_no = 0;
    for(int child : tree[src]){
        if(child == par) continue;
        int left = (child_no == 0) ? 0 : prf[child_no-1];
        int right = (child_no == suf.size()-1) ? 0 : suf[child_no + 1];
        dp[src][1] = max(dp[src][1], left + right + 1 + dp[child][0]);
        child_no++;
    }
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> tree(n+1, vector<int>());

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    memset(dp, 0, sizeof dp);

    f(tree, 1, 0);
    cout << max(dp[1][0], dp[1][1]) << endl;
}

/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t;
    //cin >> t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
