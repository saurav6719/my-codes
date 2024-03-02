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
vector<int> dp;
int f(int n,int x, vector<int> &input){
    for(int i = 1; i<=x; i++){
        int y = INT_MAX;
        for(int j = 0; j<n; j++){
            if(i-input[j] < 0 ) continue;
            y = min(y, dp[i-input[j]]);
        }
        dp[i] = 1+y;
    }
    return dp[x];
}
void solve(){
    int n;
    int x;
    cin>>n>>x;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    dp.clear();
    dp.resize(x+5,INT_MAX);
    dp[0] = 0;
    f(n,x,input);
    // for(int i = 0; i<20; i++){
    //     cout<<dp[i]<<" ";
    // }
    if(f(n,x,input) > INT_MAX-500){
        cout<<-1;
        return;
    }
    cout<<f(n,x,input);

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

