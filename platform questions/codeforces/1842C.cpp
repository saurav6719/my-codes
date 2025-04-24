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
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    map<int,int> mp;
    vector<int> nxt(n);
    nxt[n-1] = n;
    mp[input[n-1]] = n-1;

    for(int i = n-2; i>=0; i--){
        int ele = input[i];
        if(mp.count(ele)){
            nxt[i] = mp[ele];
            mp[ele] = i;
        }
        else{
            nxt[i] = n;
            mp[ele] = i;
        }
    }


    vector<int> dp(n+5, 0);
    dp[n-1] = 0;

    for(int i = n-2; i>=0; i--){
        int xx = nxt[i];
        if(xx == n){
            dp[i] = max(dp[i+1] , 0ll);
            continue;
        }
        int yy = dp[xx] + xx-i ;
        int zz = dp[xx+1] + xx-i+1;
        dp[i] = mx(dp[i+1], yy, zz);
    }

    //print(nxt);
    cout<<dp[0]<<endl;
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

