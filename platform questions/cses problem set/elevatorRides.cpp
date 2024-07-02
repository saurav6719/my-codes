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
#define pp pair<int,int> 
using namespace std;

/* write core logic here */
pp dp[(1<<20) + 5];

void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    for(int i = 0; i<(1<<20)+5; i++){
        dp[i] = {-1,-1};
    }

    dp[0] = {1, 0};
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    for(int mask = 1; mask < (1<<n); mask++){
        pp ans = {INT_MAX, INT_MAX};
        for(int j = 0; j<n; j++){
        if((mask & (1<<j))){
            pp aa = dp[mask ^ (1<<j)];
            if(aa.second + input[j] <= k){
                aa.second += input[j];
            }
            else{
                aa.second = input[j];
                aa.first++;
            }
            if(aa.first < ans.first) ans = aa;
            if(aa.second < ans.second) ans = aa;
        }   
        dp[mask] = ans;
    }
}

cout<<dp[(1<<n)-1].first;
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

