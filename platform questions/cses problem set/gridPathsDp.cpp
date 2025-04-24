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
vector<vector<int> >dp;
int f(vector<string> &grid , int i, int j, int n){
    //base case 

    if(grid[n-1][n-1] == '*'){
        dp[n-1][n-1] = 0;
        return 0;
    }
    else{
        dp[n-1][n-1] = 1;
    }
    for(int i = n-2; i>=0; i--){
        if(grid[n-1][i] == '*'){
            dp[n-1][i] = 0;
            continue;
        }
        dp[n-1][i] = (dp[n-1][i+1]) % mod;
    }

    for(int i = n-2 ; i>=0; i--){
        if(grid[i][n-1] == '*'){
            dp[i][n-1] = 0;
            continue;
        }
        dp[i][n-1] = dp[i+1][n-1]  % mod;
    }

    for(int i = n-2; i>=0;i--){
        for(int j = n-2; j>=0; j--){
            if(grid[i][j] == '*'){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = (dp[i+1][j] % mod + dp[i][j+1] %mod) % mod;
        }
    }
    return dp[0][0];
}
void solve(){
    int n;
    cin>>n;
    vector<string> grid(n);
    for(int i = 0; i<n; i++){
        cin>>grid[i]; 
    }
    dp.resize(n, vector<int> (n,-1));
    cout<<f(grid,0,0,n);
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

