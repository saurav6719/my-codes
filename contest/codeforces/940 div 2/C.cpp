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
    
    debug(left);
    
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
    vector<int> dp(3e5+5,0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;

    for(int i = 3; i<=3e5+5; i++){
      dp[i] = ((dp[i-1]%mod) + ((((i-1)%mod * dp[i-2]%mod) % mod * 2 % mod)%mod) %mod) %mod;
    }

    
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        set<int> st;
        for(int i = 0; i<k; i++){
          int ri,ci;
          cin>>ri>>ci;
          st.insert(ri);
          st.insert(ci);
        }
        int left = n - st.size();
        cout<<dp[left]<<endl;
    }
return 0;
}

