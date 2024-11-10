/**
 *    author: Saurav
 *    created: 2024.11.11 03:47:11
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
// #define mod 1000000007
#define MOD 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to find modular inverse using Fermat's Little Theorem
long long mod_inv(long long x, long long mod) {
    return mod_pow(x, mod - 2, mod);
}

// Function to calculate sum of GP
long long sum_of_gp(long long a, long long r, long long n) {
    if (r == 1) {
        return (a * n) % MOD;  // If r = 1, the sum is simply a * n
    } else {
        long long r_pow_n = mod_pow(r, n, MOD);  // Calculate r^n % MOD
        long long numerator = (r_pow_n - 1 + MOD) % MOD;  // (r^n - 1) % MOD
        long long denominator = (r - 1 + MOD) % MOD;  // (r - 1) % MOD
        long long denominator_inv = mod_inv(denominator, MOD);  // Modular inverse of (r - 1)
        return (a * numerator % MOD * denominator_inv % MOD) % MOD;
    }
}
/* write core logic here */
void solve(){
    int n;
    cin>>n;

    if(n&1){
        int xx = n/2;
        if(xx & 1){
            int start = 1;
            int r = 9;
            int size = xx/2 + 1;
            int ans1 = sum_of_gp(start,r,size);
            int ans2 = sum_of_gp(1,r,size-1);
            int ans = (ans1%MOD+ans2%MOD)%MOD;
            ans *= 4;
            ans %= MOD;
            cout<<ans<<endl;
        }
        else{
            int start = 3;
            int r = 9;
            int size = xx/2;
            int ans1 = sum_of_gp(start,r,size);
            int ans2 = sum_of_gp(1,r,size-1);

            int ans = (ans1%MOD+ans2%MOD)%MOD;
            ans *= 4;
            ans %= MOD;
            cout<<ans<<endl;

        }
    }
    else{
        int size = (n-1) / 2;
        debug(size);
        int ans = sum_of_gp(4,3,size);
        debug(ans);
        // ans *= 4;
        ans %= MOD;
        cout<<ans<<endl;
        return;
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}