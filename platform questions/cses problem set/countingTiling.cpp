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
void generatem(vector<int> &v, int mask, int i , int n, int new_mask){
    if(i==n){
        v.push_back(new_mask);
        return;
    }
    if((mask & (1<<i)) != 0){
        generatem (v, mask, i+1, n, new_mask);
    }
    if(i<n-1 and ((mask & (1<<i)) == 0) and ((mask & (1<<(i+1))) == 0)){
        generatem(v,mask, i+2, n, new_mask);
    }

    if((mask & (1<<i)) == 0){
        generatem (v, mask, i+1, n, new_mask + (1<<i));
    }
    return;
}
int dp[1001][(1<<10)+1];
int f(int col , int m, int curr_mask, int n){
    if(col == m){
        if(curr_mask == 0) return 1;
        return 0;
    }

    if(dp[col][curr_mask] != -1) return dp[col][curr_mask];
    vector<int> next_masks;
    
    int ans = 0;
    generatem(next_masks, curr_mask, 0, n, 0);
    //print(next_masks);
    for(auto ele : next_masks){
        ans += f(col+1 , m, ele , n);
        ans %= mod;
    }
    return dp[col][curr_mask] = ans;

}
void solve(){
    int n,m;
    cin>>n>>m;
    memset(dp , -1 , sizeof dp);

    cout<<f(0, m, 0, n);

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

