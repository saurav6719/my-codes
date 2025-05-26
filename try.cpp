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
#endif
#define endl "\n"
#define MOD 1000000007
#define mod_add(a, b) (((a) % MOD + (b) % MOD) % MOD)
#define mod_sub(a, b) ((((a) % MOD - (b) % MOD) + MOD) % MOD)
#define mod_mul(a, b) (((1LL * (a) % MOD) * (b) % MOD) % MOD)
// #define int long long int
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<long long , int>
using namespace std;

/* write core logic here */
vector<int> factors(int x){
    vector<int> ans;
    for(int i = 1; i*i <= x; i++){
        if(x % i == 0){
            ans.push_back(i);
            if(i != x/i){
                ans.push_back(x/i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    if(ans[0] == 1){
        ans.erase(ans.begin()); // remove 1 if present
    }
    return ans;
}
vector<int> dp;
int f2(int mul, int k){
    if(mul == 1) return 0;
    if(dp[mul] != -1) return dp[mul];
    int ans = 1e9;
    vector<int> fac1 = factors(mul);
    for(auto i : fac1){
        if(i> k) break;
        ans = min(ans, f2(mul/i, k) + 1);
    }
    return dp[mul] = ans;
}

void solve(){
    int x,y,k;
    cin>>x>>y>>k;
    int gcd = __gcd(x, y);
    x /= gcd;
    y /= gcd;
    int ans = 0;

    dp.clear();
    dp.resize(x+1, -1);
    int ans1 = f2(x, k);
    dp.clear();
    dp.resize(y+1, -1);
    int ans2 = f2(y, k);

    if(ans1 + ans2 > 1e8){
        cout<<-1<<endl;
        return;
    }

    cout<<ans1+ans2<<endl;
    return;
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