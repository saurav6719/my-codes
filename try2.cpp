/**
 *    author: Saurav
 *    created: 2026.01.11 16:57:08
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
int maximalRectangle(vector<vector<char>>& arr) {
    
        int ans = 0;
        int n = arr.size();
        int m = arr[0].size();

        vector<vector<int> > matrix(n, vector<int> (m));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                matrix[i][j] = arr[i][j] - '0';
            }
        }

        vector<vector<int> > dp(n, vector<int> (m));
        for(int j = 0; j<m; j++){
            if(matrix[n-1][j] == 0){
                debug(j);
                dp[n-1][j] = n-1;
            }
            else dp[n-1][j] = n;
        }

        for(int i = n-2; i>=0; i--){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 0){
                    dp[i][j] = i;
                }
                else{
                    dp[i][j] = dp[i+1][j];
                }
            }
        }


        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 0) continue;
                int best = 500;
                for(int l = j; l<m; l++){
                    // j se l tak all one
                    if(matrix[i][l] == 0) break;
                    best = min(best, dp[i][l]);
                    ans = max(ans, (l - j +1) * (best - i));
                }
            }
        }
        return ans;
    }
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char> > matrix(n, vector<char> (m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>matrix[i][j];
        }
    }
    print2d(matrix);
    int res = maximalRectangle(matrix);
    cout<<res<<endl;
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

