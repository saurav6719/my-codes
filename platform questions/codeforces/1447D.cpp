/**
 *    author: Saurav
 *    created: 2024.10.16 00:08:07
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
int dp[5001][5001];
int lcs(string &s1, string &s2, int i, int j){
    int n = s1.size();
    int m = s2.size();
    if(i == n || j == m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if(s1[i] == s2[j]){
        ans = lcs(s1,s2,i+1, j+1) + 2;
    }

    ans = max({ans, lcs(s1,s2,i+1,j) - 1, lcs(s1,s2,i,j+1) - 1});
    return dp[i][j] = ans;
}
void solve(){
    int n,m;
    cin>>n>>m;
    string s1,s2;
    cin>>s1>>s2;
    memset(dp,-1,sizeof dp);
    int ans = lcs(s1,s2,0,0);
    for(int i= 0; i<n; i++){
        for(int j = 0; j<m; j++){
            ans = max(ans,dp[i][j]);
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

