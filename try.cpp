/**
 *    author: Saurav
 *    created: 2024.10.27 21:07:40
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

// Function to calculate power in modular arithmetic
long long power_mod(long long x, long long y) {
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
    long long res = 1;
    for (int i = 2; i <= n; ++i)
        res = (res * i) % MOD;
    return res;
}

// Function to calculate nCr in modular arithmetic
long long nCr(int n, int r) {
    if (r == 0 || r == n)
        return 1;
    long long numerator = factorial(n);
    long long denominator = (factorial(r) * factorial(n - r)) % MOD;
    return (numerator * power_mod(denominator, MOD - 2)) % MOD;
}

// Safe comparison function
bool isGreater(long long a, long long b, int power) {
    if (b <= 0) {
        // Depending on the problem constraints, handle b <= 0 accordingly.
        // Here, assuming b > 0 based on the initial code logic.
        return false;
    }

    if (power >= 60) { // 2^60 > 1e18, which exceeds LLONG_MAX when multiplied by b >=1
        return false; // 2^power * b > a for any a <= 1e18
    }

    long long power_of_two = 1LL << power;

    // Check for potential overflow in multiplication
    if (power_of_two > LLONG_MAX / b) {
        return false; // 2^power * b would overflow, thus it's greater than a
    }

    long long product = power_of_two * b;

    return a > product;
}

void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    vector<int> dp(n);

    vector<int> afterdivide(n);
    for(int i = 0; i<n; i++){
        int ele = input[i];
        int curr = 0;
        while(ele % 2 == 0 && ele != 0){
            curr ++;
            ele /= 2;
        }

        dp[i] = curr;

        afterdivide[i] = ele;
    }

    vector<int> dp2 = dp;

    for(int i = 1; i<n; i++){
        dp[i] += dp[i-1];
        dp[i] %= mod;
    }

    print(dp);
    
    print(afterdivide);

    vector<int> prfafterdivide(n);
    prfafterdivide[0] = afterdivide[0];
    for(int i = 1; i<n; i++){
        prfafterdivide[i] = prfafterdivide[i-1] + afterdivide[i];
        prfafterdivide[i] %= mod;
    }

    print(prfafterdivide);
    vector<int> ans(n);
    ans[0] = input[0] % mod;

    // Correct Initialization
    int currbigggest = input[0];
    int currbiggestidx = 0;

    int powerafterbiggest = dp2[0];

    for(int i = 1; i<n; i++){
        int powertilli = dp[i-1];

        int currele = input[i];

        bool xx = false;

        // Use safe comparison
        xx = isGreater(currbigggest, currele, powertilli);

        if(xx){
            // ans[currbiggestidx] is already modulo'd
            ans[i] = ans[currbiggestidx];
            ans[i] %= mod;
            // Calculate prfafterdivide[i-1] - prfafterdivide[currbiggestidx]
            if(currbiggestidx > 0){
                ans[i] += (prfafterdivide[i-1] - prfafterdivide[currbiggestidx] + mod) % mod;
            }
            else{
                ans[i] += prfafterdivide[i-1];
            }
            ans[i] %= mod;

            // Compute currele * 2^(powerafterbiggestcopy) % mod
            int powerafterbiggestcopy = powerafterbiggest - dp2[currbiggestidx];
            powerafterbiggestcopy %= mod; // Ensure within mod

            // To prevent negative powerafterbiggestcopy
            if(powerafterbiggestcopy < 0){
                powerafterbiggestcopy += mod;
            }

            ans[i] += (currele % mod * power_mod(2, powerafterbiggestcopy) % mod) % mod;
            ans[i] %= mod;
            
            powerafterbiggest += dp2[i];
            powerafterbiggest %= mod;
        }
        else{
            // Add prfafterdivide[i-1] directly
            ans[i] = prfafterdivide[i-1];
            ans[i] %= mod;

            // Add currele * 2^(powertilli) % mod
            ans[i] += (currele % mod * power_mod(2, powertilli) % mod) % mod;
            ans[i] %= mod;

            // Update current biggest
            currbiggestidx = i;
            currbigggest = currele;
            powerafterbiggest = dp2[i];
        }
    }

    for(auto ele : ans){
        cout<<ele<<" ";
    }
    cout<<endl;
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
    while(t--){
        solve();
    }
    return 0;
}
