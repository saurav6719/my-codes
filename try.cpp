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
#define int long long int
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
void solve(){
  int n,k;
  cin>>n>>k;
  k = 2*n - k + 1;
  int lo = max(1LL, k - n), 
    hi = min(n, k- 1LL); 
  int best = 1e10;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    cout << "F " << n + 1 - mid << "\n" << flush;
    long long one;  cin >> one;
    cout << "S " << (n + 1 - (k - mid)) << "\n" << flush;
    long long two;  cin >> two;

    best = min(best, max(one, two));

    if (one > two) {
        // too many from Finland → shrink mid
        hi = mid - 1;
    } else {
        // too few from Finland → grow mid
        lo = mid + 1;
    }
}

// first se 0 

if(k <= n){
    cout << "S " << (n + 1 - k) << "\n" << flush;
    int x;
    cin>>x;
    if(x < best) best = x;
}

// first se saara 
if(k>=n){
    cout << "F " << 1 << "\n" << flush;
    int x;
    cin>>x;
    int y;

    if(k - n > 0){
        cout << "S " << (n + 1 - (k - n)) << "\n" << flush;
        cin>>y;
    }
    else y = 0;
    if(max(x, y) < best) best = max(x, y);
}

// second se 0 

if(k <= n){
    cout << "F " << (n + 1 - k) << "\n" << flush;
    int x;
    cin>>x;
    if(x < best) best = x;
}

// second se saara 
if(k >= n){
    cout << "S " << 1 << "\n" << flush;
    int x;
    cin>>x;
    int y;

    if(k - n > 0){
        cout << "S " << (n + 1 - (k - n)) << "\n" << flush;
        cin>>y;
    }
    else y = 0;
    if(max(x, y) < best) best = max(x, y);
}

  cout<<"! "<<best<<endl<<flush;
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

