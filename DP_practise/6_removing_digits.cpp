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
    
    int res = INT_MAX;
    for(int j = 10; j<=n; j++){
        int n_copy = j;
        vector<int> digits;
        while(n_copy > 0){
            digits.push_back(n_copy % 10);
            n_copy/=10;
        }
        for(int i = 0; i<digits.size(); i++){
            if(digits[i] == 0)continue;
            dp[j] = min(dp[j], dp[j-digits[i]]);
        }
        dp[j] = 1+dp[j];
    }
    return dp[n] ;

}
void solve(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+5,INT_MAX);
    for(int i = 1; i<=9; i++){
        dp[i] = 1;
    }
    cout<<f(n);
    

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

