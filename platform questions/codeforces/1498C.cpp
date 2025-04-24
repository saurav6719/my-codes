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
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int> > dp(k+1, vector<int> (n+1));
    bool ltr = false;
    for(int i = 0; i<n+1; i++){
        dp[k][i] = 1;
    }

    for(int i = k-1; i>0; i--){
        if(ltr){
            dp[i][0] = 0;
            for(int j = 1; j<n+1; j++){
                dp[i][j] = dp[i][j-1] + dp[i+1][j];
                dp[i][j] %= mod;
            }
            ltr = false;
        }
        else{
            dp[i][n] = 0;
            for(int j = n-1; j>=0; j--){
                dp[i][j] = dp[i][j+1] + dp[i+1][j];
                dp[i][j] %= mod;
            }
            ltr = true;
        }
    }

    int ans = 1;

    for(int i = 1; i<k; i++){
        ans += dp[i][0];
        ans %= mod;
        ans += dp[i][n];
        ans %= mod;
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

