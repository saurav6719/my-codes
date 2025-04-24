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
    vector<int> mp(15);

    mp[0] = 0;
    mp[1] = 1;
    mp[2] = 2;
    mp[3] = 1;
    mp[4] = 2;
    mp[5] = 3;
    mp[6] = 1;
    mp[7] = 2;
    mp[8] = 3;
    mp[9] = 2;
    mp[10] = 1;
    mp[11] = 2;
    mp[12] = 2;
    mp[13] = 2;
    mp[14] = 3;
    if(n<15){
        cout<<mp[n]<<endl;
        return;
    }

    int fifteen = n/15;
    n%=15;
    int ans = 0;
    ans += fifteen;
    //debug(ans);
    int x = INT_MAX;
    
    if(n>=5) x =  mn(x,mp[n], 1+mp[n-5]);//debug(x);// 1 10 
    if(n>=3) x =  mn(x,mp[n], 2+mp[n-3]); //debug(x);
    x =  mn(x,mp[n], 5+mp[n]);
    x = mn(x,mp[n],15+mp[n]);
    ans+=x;
    
   
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

