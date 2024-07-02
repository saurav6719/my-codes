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
int dp[105][1005];
int f(int i , int n , vector<int> & arr, int k){
    if(k == 0) return 1;
    if(k < 0) return 0;
    if(i == n) return 0;
    if(dp[i][k] != -1) {
        return dp[i][k];
    }
    //pick 
	int ans = 0;
    int xx = f(i+1, n, arr, k-arr[i]);
    ans += xx;
	ans = ans % 1000000007;
    //not pick 
    int yy = f(i+1, n, arr, k);
    ans += yy;
	ans = ans % 1000000007;

    return dp[i][k] = ans;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int k; cin>>k;
    memset(dp, -1, sizeof dp);
	cout<< f(0, arr.size(), arr, k)<<endl;
    for(int i = 0; i<n; i++){
        cout<<dp[i][k]<<" ";
    }
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

