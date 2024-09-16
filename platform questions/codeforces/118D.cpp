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
#define mod 100000000
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
int dp[201][11][11][101];
int f(int i, int consecutivepaidal, int consecutiveghoda, int n1, int n2, int k1, int k2, int remainingpaidal){
    
    int usedpaidal = n1 - remainingpaidal;
    int usedghoda = i - 1 - usedpaidal;
    int remainingghoda = n2 - usedghoda;
    
    if (i == (n1 + n2 + 1)) {
        return 1;  // Base case, successfully arranged
    }

    // Memoization check
    if (dp[i][consecutivepaidal][consecutiveghoda][remainingpaidal] != -1) 
        return dp[i][consecutivepaidal][consecutiveghoda][remainingpaidal];

    int ans = 0;

    // Case 1: Place a paidal (foot soldier)
    if (consecutivepaidal < k1 && remainingpaidal > 0) {
        ans += f(i + 1, consecutivepaidal + 1, 0, n1, n2, k1, k2, remainingpaidal - 1);
        ans %= mod;  // Modulo after addition
    }

    // Case 2: Place a ghoda (horse)
    if (consecutiveghoda < k2 && remainingghoda > 0) {
        ans += f(i + 1, 0, consecutiveghoda + 1, n1, n2, k1, k2, remainingpaidal);
        ans %= mod;  // Modulo after addition
    }

    // Store result with modulo
    debug(ans);

    if(ans < 0){
        debug(i);
        debug(f(i + 1, 0, consecutiveghoda + 1, n1, n2, k1, k2, remainingpaidal));
        debug(f(i + 1, consecutivepaidal + 1, 0, n1, n2, k1, k2, remainingpaidal - 1));

    }
    return dp[i][consecutivepaidal][consecutiveghoda][remainingpaidal] = ans % mod;
}

void solve(){
    int n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;

    memset(dp, -1, sizeof dp);

    cout<<f(1,0,0,n1,n2,k1,k2,n1) % mod;
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