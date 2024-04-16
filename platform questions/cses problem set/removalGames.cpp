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
#define inf 1e18
using namespace std;

/* write core logic here */
int sum (vector<int> &prf, int i , int j){
    if(i==0) return prf[j];
    else return prf[j] - prf[i-1];
}
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    vector<int> prf(n);
    prf[0] = input[0];
    for(int i = 1 ; i<n; i++){
        prf[i] = input[i] + prf[i-1];
    }

    vector<vector<int> > dp(n+1, vector<int> (n+1, -1 * inf));

    for(int i = 0 ;i<n; i++){
        dp[i][i] = input[i];
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            if(i==j) continue;
            dp[i][j] = max(input[i] + sum(prf,i+1,j) - dp[i+1][j], input[j] + sum(prf,i,j-1) - dp[i][j-1]);
        }
    }

    print(dp[0]);
    cout<<dp[0][n-1];
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

