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
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    vector<vector<int> > dp(n+5, vector<int> (2, INT_MAX));

    //0 - aap;
    //1 - friend;

    dp[n-1][0] = 0;
    if(n>=2) dp[n-2][0] = 0;
    if(input[n-1] == 1) dp[n-1][1] = 1;
    else dp[n-1][1] = 0;

    for(int i = n-2; i>=0; i--){
        for(int j = 0; j<2; j++){
            if(i==n-2 and j==0) continue;
            if(j==0){
                dp[i][0] = min(dp[i+1][1] , dp[i+2][1]); 
            }

            else{
                if(input[i] == 0 and input[i+1] == 0){
                    dp[i][1] = min(dp[i+1][0], dp[i+2][0]);
                }
                if(input[i] == 0 and input[i+1] == 1){
                    dp[i][1] = min(dp[i+1][0] , 1+ dp[i+2][0]);
                }
                if(input[i] == 1 and input[i+1] == 0){
                    dp[i][1] = 1 + min(dp[i+1][0], dp[i+2][0]);
                }
                if(input[i] == 1 and input[i+1] == 1){
                    dp[i][1] = min(1+dp[i+1][0], 2+dp[i+2][0]);
                }
            }
        }
    }

    cout<<dp[0][1]<<endl;


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

