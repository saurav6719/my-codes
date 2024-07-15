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

int maxReward(int k, vector<int>& work, vector<int>& reward, int n) {

    k = min(12*n , k);

    // Create a DP table
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Build the table dp[][] in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= k; w++) {
            if (work[i - 1] <= w)
                dp[i][w] = max(reward[i - 1] + dp[i - 1][w - work[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][k];
}


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> b(n);
    vector<int> c(n);
    for(int i = 0; i<n; i++){
        cin>>b[i];
    }

    for(int i = 0; i<n; i++){
        cin>>c[i];
    }

    vector<int> dp2(1005, INT_MAX);
    dp2[1] = 0;
    for(int i = 2; i<=1000; i++){
        for(int j = i-1; j>=1; j--){
            // debug(i);
            // debug(j);

            int req = i - j;

            
            //debug(req);
            int lamda = j / req;

            if(lamda == 0) continue;
            //debug(lamda);
            if(j / lamda == req){
                dp2[i] = min(dp2[i] , dp2[j] + 1);
            }
        }
    }

    //print(dp2);

    vector<int> xx(n);

    for(int i = 0; i<n; i++){
        int a = b[i];
        xx[i] = dp2[a];
    }

    //print(xx);


    

    //print(dp2);

    cout<<maxReward(k,xx, c,n)<<endl;

   


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

