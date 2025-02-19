/**
 *    author: Saurav
 *    created: 2025.02.18 21:22:12
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
#define mod 998244353
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
const int MOD = 998244353;

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
    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    vector<int> newv;
    int ii = 0;
    while(ii<n and input[ii] != 1){
        ii++;
    }

    int j = n-1;
    while(j>=0 and input[j] != 3){
        j--;
    }

    for(int a = ii; a<=j; a++){
        newv.push_back(input[a]);
    }

    int active3 = 0;
    int totalcurr =0 ;
    int piche2 = 0;
    int ans = 0;
    n = newv.size();
    for(int i = 0; i<n; i++){
        if(newv[i] == 3){
            active3++;
            totalcurr += power(2, piche2);
        }
        if(newv[i] == 2){
            piche2++;
        }
    }

    debug(totalcurr);

    for(int i = 0; i<n; i++){
        if(newv[i] == 1){
            ans += (totalcurr - active3);
            debug(totalcurr);
            debug(active3);
            debug(ans);
        }
        if(newv[i] == 2){
            totalcurr /= 2;
        }
        if(newv[i] == 3){
            active3--;
        }
    }

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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}