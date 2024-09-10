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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int> (m));
    for(int i=0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>grid[i][j];
        }
    }


    if((n+m - 1) & 1){
        cout<<"NO"<<endl;
        return;
    }

    vector<vector<pp> > dp(n, vector<pp> (m, {INT_MAX, INT_MIN}));

    dp[0][0] = {grid[0][0], grid[0][0]};

    for(int j = 1; j<m; j++){
        dp[0][j].first = dp[0][j-1].first + grid[0][j];
        dp[0][j].second = dp[0][j-1].second + grid[0][j];
    }

    for(int j = 1; j<n; j++){
        dp[j][0].first = dp[j-1][0].first + grid[j][0];
        dp[j][0].second = dp[j-1][0].second + grid[j][0];
    }

    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            dp[i][j].first = min(dp[i-1][j].first + grid[i][j] , dp[i][j-1].first + grid[i][j]);
            dp[i][j].second = max(dp[i-1][j].second + grid[i][j] , dp[i][j-1].second + grid[i][j]);
        }
    }

    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         cout<<dp[i][j].first<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         cout<<dp[i][j].second<<" ";
    //     }
    //     cout<<endl;
    // }


    int mini = dp[n-1][m-1].first;
    int maxi = dp[n-1][m-1].second;

    if(mini <=0 and maxi >= 0 ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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

