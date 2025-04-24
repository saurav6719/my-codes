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
const int MAXN = 2e5 + 5; // Adjust according to the problem constraints

// Arrays to store factorials and modular inverses
long long fact[MAXN];
long long invfact[MAXN];

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

// Function to precompute factorials and modular inverses
void precompute_factorials() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        fact[i] = fact[i-1] * i % MOD;
    }
    invfact[MAXN-1] = power(fact[MAXN-1], MOD-2);
    for (int i = MAXN-2; i >= 0; --i) {
        invfact[i] = invfact[i+1] * (i+1) % MOD;
    }
}

// Function to calculate nCr in modular arithmetic using precomputed values
long long nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}

void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> input(n);
    for(int i= 0; i<n; i++){
        cin>>input[i];
    }

    k = (k -1) / 2;

    vector<int> aageone(n, 0);

    for(int i = n-2; i>=0; i--){
        if(input[i+1] == 1){
            aageone[i] = aageone[i+1]+1;
        }
        else{
            aageone[i] = aageone[i+1];
        }
    }

    vector<int> picheone(n, 0);

    for(int i = 1; i<n; i++){
        if(input[i-1] == 1){
            picheone[i] = picheone[i-1]+1;
        }
        else{
            picheone[i] = picheone[i-1];
        }
    }

    int totalzero = 0;
    for(int i = 0; i<n; i++){
        if(input[i] == 0) totalzero++;
    }

    int ans = 0;

    for(int i =0; i<n; i++){
        if(input[i] == 0) continue;
        int xx = aageone[i];
        debug(xx);
        int y = picheone[i];
        int x = totalzero;
        int curr = 0;
        int xxx = nCr(x+y , k);
        debug(xxx);
        curr += xxx;
        curr %= mod;
        int yyy = nCr(xx, k);
        debug(yyy);
        curr *= yyy;
        curr %= mod;

        debug(i);
        debug(curr);

        ans += curr;
        ans %= mod;
    }

    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    precompute_factorials(); // Precompute factorials and inverses
    int t;
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}
