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
int dp[21][(1<<20)+5];
int f(int i , int mask, int n, vector<vector<int> > &jobs){
    if(i == n) return 0;
    if(dp[i][mask] != -1) return dp[i][mask];
    int ans = INT_MAX;
    for(int j = 0; j<n; j++){
        if(mask & (1<<j)){
            ans = min(ans , jobs[i][j] + f(i+1, mask ^ (1<<j) , n , jobs));
        }
    }
    return dp[i][mask] = ans; 

}
void solve(){
    int n;
    cin>>n;
    vector<vector<int> > jobs(n, vector<int> (n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>jobs[i][j];
        }
    }

    
    memset (dp, -1, sizeof dp);
    cout<<f(0, (1<<n) - 1 , n, jobs);
    
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

