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
int dp[101][101][101];

void solve(){
    int n,m,x;
    cin>>n>>m>>x;

    vector<int> initial(n+1);
    for(int i = 1; i<=n; i++){
        cin>>initial[i];
    }

    vector<vector<int> > prices(n+1, vector<int> (m+1));

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m;j++){
            cin>>prices[i][j];
        }
    }

    for(int i = 0; i<101; i++){
        for(int j = 0; j<101; j++){
            for(int k = 0; k<101; k++){
                dp[i][j][k] = 1e15;
            }
        }
    }

    debug(dp[2][1][1]);

    for(int i = 1; i<=1; i++){
        for(int j = 1; j<=m; j++){
            for(int k = 1; k<=1; k++){
                if(initial[i] == 0)dp[i][j][k] = prices[1][j];
                else {
                    if(j==initial[i]) dp[i][j][k] = 0;
                    else dp[i][j][k] = 1e15;
                }
            }
        }
    }

    // for(int i = 1; i<=1; i++){
    //     for(int j= 1; j<=m; j++){
    //         for(int k = 1; k<=1; k++){
    //             cout<<dp[i][j][k]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }

    for(int i = 2; i<=n; i++){
        for(int j = 1; j<=m; j++){
            for(int k = 1; k<=x; k++){
                //if already coloured
                debug(i);
                debug(j);
                debug(k);
                debug(dp[i][j][k]);
                int xx = initial[i];
                if(xx!=0 and j!=xx) continue;
                if(xx != 0){
                    // cout<<"ISME"<<endl;
                    for(int l = 1; l<=m; l++){
                        int yy;
                        if(l==xx){
                            yy = dp[i-1][l][k];
                        }
                        else yy = dp[i-1][l][k-1];

                        dp[i][j][k] = min(dp[i][j][k] , yy);
                    }
                }
                else{
                    // cout<<"USME"<<endl;
                    for(int l= 1; l<=m; l++){
                        int yy;
                        if(l==j){
                            yy = dp[i-1][l][k];
                        }
                        else yy = dp[i-1][l][k-1];

                        dp[i][j][k] = min(dp[i][j][k], prices[i][j] + yy);
                    }
                }
                debug(dp[i][j][k]);
            }
        }
    }

    int ans = 1e15;
    for(int i = n; i<=n; i++){
        for(int j = 1; j<=m; j++){
            for(int k = x; k<=x; k++){
                ans = min(ans, dp[i][j][k]);
            }
        }
    }

    if(ans >= 1e15 - 50){
        ans = -1;
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

