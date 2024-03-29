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
int dp[101][1000005];
/* write core logic here */
int  f(int n, int x,vector<int> &nums, int i){
    //base case
	dp[i][0] = 1;
    if(x<0) {
        dp[i][x] = 0;
        return 0;
    }
    if(x==0) return 1;
    if(i==n) return 0;
    if(dp[i][x] != -1) return dp[i][x];
    
    int sum = 0;
    for(int j = 1; j<=x; j++){
        if(j-nums[i] < 0) {
            dp[i][j] = 0;
            continue;
        }
        sum += f(n,j-nums[i] , nums , i); 
        if( j - nums[i] >0 )sum += f(n,j-nums[i], nums, i+1);
    }
	return dp[i][x] = sum;
}
void solve(){
    int n;
    cin>>n;
    int x; 
    cin>>x;
    vector<int> nums(n);
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }
    memset(dp, -1 , sizeof dp);
    cout<<f(n,x,nums, 0) % mod;
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