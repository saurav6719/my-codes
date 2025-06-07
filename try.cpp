/**
 *    author: Saurav
 *    created: 2025.05.01 05:23:43
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
#define printpp(v)
#define printset(s)
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
vector<vector<int>> dp;
int f(vector<int> &v,int i, int mask, int n, vector<int> &digit_mask){
    if(i == n) return 0;
    if(dp[i][mask] != -1) return dp[i][mask];

    int ans = 0;
    // skip 
    ans = f(v, i + 1, mask, n, digit_mask);
    // take it 
    if(digit_mask[i] != -1 and (mask & digit_mask[i]) == 0){
        ans = max(ans, v[i] + f(v, i + 1, mask | digit_mask[i], n, digit_mask));
    }
    return dp[i][mask] = ans;
}
vector<vector<int> > subtreeatthisnode;

vector<int> findsubtree(vector<vector<int> > &tree, int node, int par){
    vector<int> ans;
    ans.push_back(node);
    for(auto child : tree[node]){
        if(child != par){
            vector<int> temp = findsubtree(tree, child, node);
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
    }

    subtreeatthisnode[node] = ans;
    return ans;
}
int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
    int n = vals.size();
    vector<vector<int> > tree(n);

    for(int i = 0; i < n; i++){
        if(par[i] != -1){
            tree[par[i]].push_back(i);
            tree[i].push_back(par[i]);
        }
    }

    subtreeatthisnode.resize(n);

    findsubtree(tree, 0, -1);
    int res = 0;

    for(int i = 0; i<n; i++){
        dp.clear();
        vector<int> v;
        for(auto ele : subtreeatthisnode[i]){
            v.push_back(vals[ele]);
        }
        int m = v.size();
        vector<int> digit_mask(m);

        for(int j = 0; j < m; j++){
            int num = v[j];
            int mask = 0;
            while(num > 0){
                int d = num % 10;
                if(mask & (1 << d)){
                    mask = -1; 
                    break;
                }
                mask |= (1 << d);
                num /= 10;
            }
            digit_mask[j] = mask;
        }
        dp.resize(m + 1, vector<int>(1024, -1)); 
        int ans = f(v, 0, 0, m, digit_mask);
        res += ans;
        debug(i);
        debug(ans);
        print(v);
        print(digit_mask);
        res %= 1000000007;
    }
    return res;
}
void solve(){
    int n;
    cin >> n;
    vector<int> vals(n);
    for(int i = 0; i < n; i++){
        cin >> vals[i]; 
    }
    vector<int> par(n);
    for(int i = 0; i < n; i++){
        cin >> par[i];
    }

    int x = goodSubtreeSum(vals, par);
    cout<<x<<endl;
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

