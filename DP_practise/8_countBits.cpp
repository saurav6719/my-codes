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
//link -> https://leetcode.com/problems/counting-bits/
void solve(){
    class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, -1);
        for(int i = 1; i<=n; i*=2){
            ans[i] = 1;
        }
        if(n>=0) ans[0] = 0;
        if(n>=1) ans[1] = 1;
        if(n>=2) ans[2] = 1;
        int curr = 2;
        for(int i = 3; i<=n; i++){
            if(ans[i] != -1){
                curr = i;
                continue;
            }
            int diff = i - curr;
            ans[i] = ans[curr] + ans[diff];
        }

    return ans;
    }
};
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

