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
    return (numerator * power(denominator, MOD - 2)) % MOD;
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
        while(ele % 2 == 0){
            curr ++;
            ele /= 2;
        }

        dp[i] = curr;

        afterdivide[i] = ele;
    }

    vector<int> dp2 = dp;

    print(dp2);

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
    ans [0] = input[0];

    int currbigggest = -1e15;
    int currbiggestidx = -1;

    int powerafterbiggest = 0;

    for(int i = 1; i<n; i++){
        int powertilli = dp[i-1];

        int currele = input[i];

        // debug(i);
        // debug(currbigggest);
        // debug(pow(2, powerafterbiggest) * currele);
        bool xx = false;


        if(currbigggest > 0){
            int logtwocurrbiggest = log2(currbigggest);
            int yy = powerafterbiggest + log2(currele);

            if(yy > logtwocurrbiggest + 2){
                xx = false;
            }
            else if( yy < logtwocurrbiggest - 2){
                xx = true;
            }

            else{
                int aa = (power(2, powerafterbiggest) * currele);
                int bb = currbigggest;
                if(aa > bb){
                    xx = false;
                }
                else{
                    xx = true;
                }
            }   
        }

        if(xx){
            int aa = 0;
            int bb= 0;
            ans[i] = ans[i-1];
            if(i - currbiggestidx > 1){
                int ppr = power(2,dp2[i-1])% mod;
                ans[i] += (ppr  * (currele % mod)) % mod;
                ans[i] %= mod;
                ans[i] -= (input[i-1] - afterdivide[i-1]);
                ans[i] += mod;
                ans[i] %= mod;
                
            }
            else{
                ans[i] += currele;
                ans[i] %= mod;
            }
            aa = ans[i];
            ans[i] = ans[currbiggestidx];
            ans[i] %= mod;
            ans[i]+= prfafterdivide[i-1] - prfafterdivide[currbiggestidx];
            ans[i] += mod;
            ans[i] %= mod;
            int powerafterbiggestcopy = powerafterbiggest;
            powerafterbiggestcopy -= dp2[currbiggestidx];
            ans[i] += (currele%mod * power(2, powerafterbiggestcopy) %mod) %mod;

            bb = ans[i];

            ans[i] = max(aa, bb);

            powerafterbiggest += dp2[i];
            powerafterbiggest %= mod;

        }

        else{
            ans[i] = prfafterdivide[i-1];
            ans[i] %= mod;
            ans[i] += ((currele%mod * (power(2, powertilli))%mod)) %mod;
            ans[i] %= mod;
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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

