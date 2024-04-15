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
void solve(){
    string str1;
    string str2;
    cin>>str1;
    cin>>str2;
    int n = str1.size();
    int m = str2.size();

    vector<vector<int> > dp(n+5, vector<int>(m+5, 0));

    //base cases
    for(int i = 0; i<n; i++){
        dp[i][m] = n-i;
    } 

    for(int j = 0; j<m; j++){
        dp[n][j] = m-j;
    }

    for(int i = n-1; i>=0; i--){
        for(int j = m-1;j>=0;j--){
            if(str1[i] == str2[j]){
                dp[i][j] = dp[i+1][j+1];
                continue;
            }
            dp[i][j] = 1+ mn(dp[i+1][j], dp[i][j+1], dp[i+1][j+1]);
        }
    }

    cout<<dp[0][0]<<endl;
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

