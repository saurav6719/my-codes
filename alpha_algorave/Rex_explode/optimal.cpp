/**
 *    author: Saurav
 *    created: 2025.10.16 18:16:48
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
#define printset(s)
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
int n;
int x;
vector<int> input;
vector<int> pref;
int f(int l, int r){
    if(l > r) return 0;
    if(l == 0) return pref[r];
    return pref[r] - pref[l-1];
}

int dp[1001][101];
int f2(int i, int x){
    // i se n-1 kaa answer if i pe explode krunga and av x explosion bache hai 
    if(i >= n) return 0;
    if(x == 0) return input[i];
    if(dp[i][x] != -1) return dp[i][x];

    int ans = input[i];
    for(int j = i+1; j<=min(n, i+input[i]) ; j++){
        ans = max(ans, f(i+1, j-1) + f2(j, x-1));
    }
    return dp[i][x] = ans;
}
void solve(){
    cin>>n;
    cin>>x;
    input.resize(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    pref.resize(n);
    pref[0] = input[0];
    for(int i = 1; i<n; i++){
        pref[i] = pref[i-1] + input[i];
    }

    memset(dp, -1, sizeof(dp));
    int ans = f2(0, x);
    cout << ans << endl;
    

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

