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
bool binarydecimal(int n){
  while(n>0){
    int md = n%10;
    n/=10;
    if(md != 0 and md != 1) return false;
  }
  return true;
}
vector<bool> dp(1e5+5);
void solve(){
    int n;
    cin>>n;
    if(dp[n] == true){
      cout<<"YES"<<endl;
      return;
    }
    cout<<"NO"<<endl;

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

    
    dp[1] = true;
    for(int i = 2; i<=1e5; i++){
      if(binarydecimal(i)){
        dp[i] = true;
        continue;
      }
      int sqrt_n = sqrt(i);
      //debug(sqrt(i));
      for (int j = 1; j <= sqrt_n; j++) {
        // If i divides n evenly, it's a factor
        if (i % j == 0) {
            if(dp[j]== true and dp[i/j] == true){
              dp[i] = true;
              break;
            }
        }
      }
    }

    while(t--){
        solve();
    }
return 0;
}

