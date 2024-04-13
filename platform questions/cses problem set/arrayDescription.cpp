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
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    vector<int> prev(m+5,0);
    for(int i = 1; i<=m; i++){
        if(input[0] != 0 and input[0] != i){
            prev[i] = 0;
        }
        else{
            prev[i] = 1;
        }
    }

    for(int i = 1; i<n; i++){
        vector<int> curr(m+5,0);
        for(int j = 1; j<=m; j++){
            if(input[i] != 0 and input[i] != j){
                curr[j] = 0;
                continue;
            }
            curr[j] = (((prev[j] % mod) + (prev[j-1]%mod)) % mod + (prev[j+1]%mod)) % mod;
        }
        prev = curr;
    }

    int ans = 0;
    for(int i = 1; i<=m; i++){
        ans = ((ans %mod) + (prev[i]%mod)) % mod;
    }
    cout<<ans;

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

