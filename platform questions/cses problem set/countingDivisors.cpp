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
vector<int> dp(1e6+5,-1);
void solve(){
    int x;
    cin>>x;
    int x_copy = x;
    vector<int> powers;
    if(dp[x_copy] != -1) {
        cout<<dp[x]<<endl;
        return;
    }

    for(int i = 2; i * i <= x ; i++){
        if(x % i ==0){
            int alpha = 0;
            while(x % i==0){
                alpha++;
                x /= i;
            }
            powers.push_back(alpha);
        }
    }


    if(x > 1){
        powers.push_back(1);
    }

    int ans = 1;
    for(auto ele : powers){
        ans *= (ele+1);
    }
    dp[x_copy] = ans;
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

