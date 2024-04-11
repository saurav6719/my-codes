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
int n;
int x;
vector<int> dp;
vector<int> prices;
vector<int> pages;
int f(int j){
    for(int i = n-1;i>=0; i--){
        for(int j = x; j>=0;j--){
            dp[j] = max(dp[j] , (j>= prices[i]) ? dp[j - prices[i]] + pages[i] : INT_MIN);
        }
    }
    return dp[j];
}

void solve(){
    cin>>n;
    cin>>x;
    pages.resize(n);
    prices.resize(n);
    dp.clear();
    dp.resize(x+5,0);
    for(int i= 0;i<n; i++){
        cin>>prices[i];
    }
    for(int i = 0; i<n; i++){
        cin>>pages[i];
    }
    cout<<f(x);
    
    
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

