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
vector<vector<int> > dp;
int f(vector<int> &input, int s, int sum, int cnt, bool poss, int i, int j){

    if(i>=input.size()) return dp[i][j] = INT_MAX;
    if(j<0) return dp[i][j] = INT_MAX;
    // debug(s);
    // debug(sum);
    if(dp[i][j] != -1) return dp[i][j];
    if(poss){
        return dp[i][j] = cnt;
    }  
    if(sum == s) {
        poss = true;
        return dp[i][j] = cnt;
    }
    if(sum < s) return INT_MAX;
    return dp[i][j] = min(f(input,s,sum - input[i], cnt + 1, poss, i+1, j) ,  f(input,s,sum - input[j], 1+cnt, poss, i, j-1));
}
void solve(){

    dp.clear();
    
    
    int n,s;
    cin>>n>>s;
    dp.resize(n+5, vector<int> (n+5, -1));
   // debug(dp[0][0]);
    vector<int> input(n);
    int t_sum = 0;
    for(int i = 0; i<n; i++){
        cin>>input[i];
        t_sum += input[i];
    }
    int cnt = 0;
    int ans = f(input,s,t_sum,0,false,0,n-1);
    if(ans >= INT_MAX - 1000000) ans = -1;
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

