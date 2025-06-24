/**
 *    author: Saurav
 *    created: 2025.06.24 20:18:17
 *    We stop at Candidate Master in 2025
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

#define printset(s) do { \
    cout << "set-- starts" << endl; \
    for (auto it = s.begin(); it != s.end(); ++it) { \
        cout << *it << endl; \
    } \
    cout << "set-- ends" << endl; \
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
#define printset(s)
#define printpp(v)
#endif
#define endl "\n"
#define MOD 1000000007
#define mod_add(a, b) (((a) % MOD + (b) % MOD) % MOD)
#define mod_sub(a, b) ((((a) % MOD - (b) % MOD) + MOD) % MOD)
#define mod_mul(a, b) (((1LL * (a) % MOD) * (b) % MOD) % MOD)
#define int long long int
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
int n;
vector<vector<int>> adj;
vector<int> coins;
vector<int> dp;
vector<bool> has_coin;
int minCost = INT_MAX;

bool dfs(int u, int par) {
    bool coin_here = (coins[u] == 1);
    int cost = 0;
    for (int v : adj[u]) {
        if (v == par) continue;
        if (dfs(v, u)) {
            coin_here = true;
            cost += dp[v] + 2;
        }
    }
    has_coin[u] = coin_here;
    dp[u] = cost;
    return coin_here;
}

void reroot(int u, int par) {
    minCost = min(minCost, dp[u]);

    for (int v : adj[u]) {
        if (v == par) continue;

        int up = dp[u], down = dp[v];
        bool had_coin_u = has_coin[u], had_coin_v = has_coin[v];

        // Remove v's contribution from u
        if (has_coin[v]) dp[u] -= dp[v] + 2;
        has_coin[u] = has_coin[u] && !has_coin[v];

        // Add u's (remaining) contribution to v
        if (has_coin[u]) dp[v] += dp[u] + 2;
        has_coin[v] = has_coin[v] || has_coin[u];

        reroot(v, u);

        // Restore
        dp[v] = down; dp[u] = up;
        has_coin[v] = had_coin_v;
        has_coin[u] = had_coin_u;
    }
}


int getMinPath(vector<int> &coin, vector<int> &from, vector<int> &to) {
    n = coin.size();
    adj.assign(n, {});
    coins = coin;
    dp.assign(n, 0);
    has_coin.assign(n, false);
    
    for (int i = 0; i < from.size(); i++) {
        adj[from[i]].push_back(to[i]);
        adj[to[i]].push_back(from[i]);
    }

    dfs(0, -1);         // step 1
    reroot(0, -1);      // step 2
    return minCost;
}
void solve(){
    cin>>n;
    vector<int> coin(n);
    for(int i=0; i<n; i++){
        cin>>coin[i];
    }
    vector<int> from(n-1), to(n-1);
    for(int i=0; i<n-1; i++){
        cin>>from[i]>>to[i];
    }

    int result = getMinPath(coin, from, to);
    cout << result << endl;

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

