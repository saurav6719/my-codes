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
    int a;
    int b;
    cin>>a>>b;
    vector<vector<int> > dp(a+5, vector<int> (b+5, INT_MAX));

    for(int i = 1; i<=a; i++){
        for(int j = 1; j<=b; j++){
            if(i==j){
                dp[i][j] = 0;
            }
        }
    }

    for(int i = 1; i<=a; i++){
        for(int j = 1; j<=b; j++){
            debug(i);
            for(int k = 1; k<=i-1; k++){
                dp[i][j]= min(dp[i][j],1 + dp[k][j] + dp[i-k][j]);
            }

            for(int l = 1; l<=j-1; l++){
                dp[i][j]= min(dp[i][j],1 + dp[i][l] + dp[i][j-l]);
            }
        }
    }

    cout<<dp[a][b];






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

