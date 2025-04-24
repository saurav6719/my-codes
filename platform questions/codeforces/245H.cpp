/**
 *    author: Saurav
 *    created: 2024.10.20 12:45:34
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
// #define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
int dp[5001][5001] ;

int f(string &str, int i, int j){
    if(j-i == 1){
        if(str[i] == str[j]) return dp[i][j] = 1;
        return dp[i][j] = 0;
    }

    if(i > j) return dp[i][j] = 0;
    if(i == j) return dp[i][j] = 1;
    if(dp[i][j] != -1) return dp[i][j] ;

    if(str[i] == str[j]){
        return dp[i][j] = f(str,i+1,j-1) ;
    }
    return dp[i][j] = 0 ;
}
void solve(){
    string str;
    cin>>str;
    int q;
    cin>>q;

    int n = str.size() ;
    memset(dp,-1,sizeof dp);

    for(int i= 0; i<n; i++){
        for(int j = 0; j<n; j++){
            f(str,i,j) ;
        }
    }

    vector<vector<int> > prefix2dsum(n,vector<int>(n,0)) ;

    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<n; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i == 0 && j == 0){
                prefix2dsum[i][j] = dp[i][j] ;
            }
            else if(i == 0){
                prefix2dsum[i][j] = prefix2dsum[i][j-1] + dp[i][j] ;
            }
            else if(j == 0){
                prefix2dsum[i][j] = prefix2dsum[i-1][j] + dp[i][j] ;
            }
            else{
                prefix2dsum[i][j] = prefix2dsum[i-1][j] + prefix2dsum[i][j-1] - prefix2dsum[i-1][j-1] + dp[i][j] ;
            }
        }
    }

    print2d(prefix2dsum) ;

    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        int a = prefix2dsum[r][r] ;
        int b = 0;
        if(l > 0){
            b = prefix2dsum[l-1][r] ;
        }
        int c = 0;
        if(l > 0){
            c = prefix2dsum[r][l-1] ;
        }
        int d = 0;
        if(l > 0){
            d = prefix2dsum[l-1][l-1] ;
        }
        cout<<a-b-c+d<<endl;
    }




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

