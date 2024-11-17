/**
 *    author: Saurav
 *    created: 2024.11.17 16:50:13
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
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
const int MOD = 998244353;

vector<int> factorialdp(300001);

void precompute(){
    factorialdp[0] = 1;
    factorialdp[1] = 1;
    for(int i = 2; i<=300000; i++){
        factorialdp[i] = i * factorialdp[i-1];
        factorialdp[i] %= MOD;
    }
}
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

// Function to calculate factorial in modular arithmetic
long long factorial(int n) {
    return factorialdp[n];
}

// Function to calculate nCr in modular arithmetic
long long nCr(int n, int r) {
    if (r == 0 || r == n)
        return 1;
    long long numerator = factorial(n);
    long long denominator = (factorial(r) * factorial(n - r)) % MOD;
    return (numerator * power(denominator, MOD - 2)) % MOD;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(2*n);

    for(int i =0; i<2*n; i++){
        cin>>a[i];
    }
    
    sort(a.begin(), a.end());
    int ans = 0;
    int i = 0; 
    int j = (2*n)-1;

    while(i<j){
        ans += a[j] - a[i];
        i++;
        j--;
    }

    int x = n-1;
    int tomul = 0;
    for (int x = n - 1; x < 2 * n; ++x) {
        tomul = (tomul + nCr(x, n - 1)) % MOD;
    }


    ans %= MOD;

    ans *= tomul;
    ans %= MOD;

    cout<<ans<<endl;


    
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
    precompute();
    while(t--){
        solve();
    }
return 0;
}

