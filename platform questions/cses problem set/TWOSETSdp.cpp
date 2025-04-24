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
    int n;
    cin>>n;
    int sum = n*(n+1)/2;
    if(sum&1){
        cout<<0;
        return;
    }
    //cout<<dp[0]<<endl;

    vector<vector<int> > dp(n+5, vector<int> (sum+5, 0));

    dp[0][0] = 1;
    for(int i = 1; i<=n ;i++){
        dp[i][0] = 0;
    }
    for(int j = 1; j<=sum/2; j++){
        for(int i = 1; i<=n; i++){
            dp[i][j] = dp[i-1][j];
            if(j-i >= 0){
                dp[i][j] += dp[i-1][j-i];
            }
            dp[i][j] %= mod;
        }
    }
    cout<<dp[n][sum/2];
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

