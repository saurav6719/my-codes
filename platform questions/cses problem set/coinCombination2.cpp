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
vector<int> dp;
/* write core logic here */
int  f(int n, int x,vector<int> &nums){
    //base case
	dp[0] = 1;
    for(int i = 0 ;i<n; i++){
        for(int j = 1; j<=x; j++){
            if(j-nums[i] < 0 ) continue;
            dp[j] += (dp[j-nums[i]] % mod);
        }
    }
 
	return dp[x];
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
    dp.clear();
    dp.resize(x+5);
    cout<<f(n,x,nums) % mod;
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
