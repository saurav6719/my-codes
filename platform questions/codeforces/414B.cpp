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

vector<int> findFactors(int num) {
    vector<int> factors;
    
    for (int i = 1; i*i <= num; i++) {
        if (num % i == 0) {
            factors.push_back(i);
            if (i != num / i) {
                factors.push_back(num / i);
            }
        }
    }

    return factors;
}



void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int> > dp(n+5,vector<int> (k+5,0));
    for(int i = 1; i<=n; i++){
        dp[i][1] = 1;
    }

    vector<vector<int> >divisors(n+1);

    for(int i = 1; i<=n; i++){
        divisors[i] = findFactors(i);
    }

    for(int i = 1; i<=n; i++){
        dp[i][2] = divisors[i].size();
    }

    for(int i = 1; i<=n; i++){
        for(int j = 3; j<=k; j++){
            for(int l = 0; l<divisors[i].size(); l++){
                dp[i][j] += dp[divisors[i][l]][j-1];
                dp[i][j] %= mod;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i<=n; i++){
        ans += dp[i][k];
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

