/**
 *    author: Saurav
 *    created: 2024.10.19 03:50:35
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

void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    // Initialize DP table
    // dp[idx][even][length]
    // idx from 0 to n
    // even: 0 or 1
    // length: 0 to 3
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(4, 0)));

    // Base Case
    // At idx=0, even=1 (initial state), length=0, there's 1 way (empty subset)
    dp[0][1][0] = 1;

    for(int idx = 0; idx < n; idx++){
        for(int even = 0; even <=1; even++){
            for(int length = 0; length <=3; length++){
                if(dp[idx][even][length] == 0) continue;

                // Current element parity
                int curreven = (input[idx] & 1) ? 0 : 1;

                // Pick the current element
                int neweven = (even ^ curreven);
                neweven ^= 1; // As per original logic

                int newlength = length + 1;
                if(newlength >3) newlength =3;

                dp[idx+1][neweven][newlength] += dp[idx][even][length];
                dp[idx+1][neweven][newlength] %= mod; // To prevent overflow

                // Not pick the current element
                dp[idx+1][even][length] += dp[idx][even][length];
                dp[idx+1][even][length] %= mod;
            }
        }
    }

    // Compute the answer
    // According to the original base cases:
    // If length >=3 and even ==1, it's valid (assuming based on original conditions)
    int ans = 0;
    for(int even =0; even <=1; even++){
        for(int length =3; length <=3; length++){ // Only length=3 is meaningful due to capping
            if(length >=3){
                if(even ==1){
                    ans += dp[n][even][length];
                    ans %= mod;
                }
                // According to original code, if length >=3 and even == false, return 0
                // So we only count when even ==1
            }
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}
