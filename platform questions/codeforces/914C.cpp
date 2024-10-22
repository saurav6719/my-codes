/**
 *    author: Saurav
 *    created: 2024.10.22 21:44:25
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
const int MOD = 1e9 + 7;
const int MAX = 1000;

// Precomputed factorial and inverse factorial arrays
vector<long long> fact(MAX + 1, 1);
vector<long long> inv_fact(MAX + 1, 1);

// Function to calculate power in modular arithmetic
long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1; // y = y/2
        x = (x * x) % MOD;
    }
    return res;
}

// Function to precompute factorial and inverse factorial
void precompute() {
    // Compute factorial modulo MOD
    for(int i = 2; i <= MAX; ++i){
        fact[i] = (fact[i-1] * i) % MOD;
    }

    // Compute inverse factorial using Fermat's Little Theorem
    inv_fact[MAX] = power(fact[MAX], MOD - 2);
    for(int i = MAX -1; i >=0; --i){
        inv_fact[i] = (inv_fact[i+1] * (i+1)) % MOD;
    }
}

// Function to calculate nCr in modular arithmetic using precomputed arrays
long long nCr(int n, int r) {
    if(r > n) return 0;
    if (r == 0 || r == n)
        return 1;
    return (fact[n] * inv_fact[r] % MOD) * inv_fact[n - r] % MOD;
}

void solve(){
    string str;
    cin>>str;
    int k;
    cin>>k;

    if(k==0) {
        cout<<1<<endl;
        return;
    }

    if(str == "1"){
        cout<<0<<endl;
        return;
    }

    vector<int> dp(1001, 0);
    dp[1] = 0;

    for(int i = 2; i<=1000; i++){
        int countone = __builtin_popcount(i);
        dp[i] = 1 + dp[countone];
    }
    int n = str.size();
    debug(n);

    vector<int> rs;

    for(int i = 1; i<=1000; i++){
        if(dp[i] == k-1){
            rs.push_back(i);
        }
    }

    vector<int> mp(1005, 0);
    int ones = 0;
    vector<int> zeros;
    for(int i = 0; i<n; i++){
        if(str[i] == '0'){
            mp[i] = ones;
            zeros.push_back(i);
        }
        else{
            ones++;
        }
    }

    int ans = 0;

    for(auto ele : rs){
        if(ele > n) continue; // Changed from break to continue since rs may not be sorted
        debug(ele);
        ans += nCr(n, ele);
        ans %= MOD;

        for(auto ele2 : zeros){
            // debug(ele2);
            // debug(mp[ele2]);
            int newr = ele - mp[ele2];
            if(newr <= 0) continue; // Changed from break to continue
            // debug(n-ele2+1);
            ans -= nCr(n - ele2 - 1, newr - 1);
            if(ans < 0) ans += MOD; // Ensuring non-negative before modulo
            ans %= MOD;
        }
    }
    int onecountinstr = 0;
    for(auto ele : str){
        if(ele == '1') onecountinstr++;
    }

    if(k==1) ans--;
    cout<<ans<<endl;
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    precompute(); // Precompute factorial and inverse factorial
    int t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}
