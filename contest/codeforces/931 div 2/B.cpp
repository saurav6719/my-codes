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
vector<int> dp;
int f(int n){
    dp[0] = 0;
    for(int i = 1; i<=1e9+4; i++){
        if(i>=1) dp[i] = min(dp[i], dp[i-1]);
        if(i>=3) dp[i] = min(dp[i], dp[i-3]);
        if(i>=6) dp[i] = min(dp[i], dp[i-6]);
        if(i>=10) dp[i] = min(dp[i], dp[i-10]);
        if(i>=15) dp[i] = min(dp[i], dp[i-15]);
        dp[i]++;
    }
}
void solve(){
    int n;
    cin>>n;
    cout<<dp[n]<<endl;
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
    dp.clear();
    dp.resize(1e9+5,INT_MAX);
    f(1e9+5);
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

