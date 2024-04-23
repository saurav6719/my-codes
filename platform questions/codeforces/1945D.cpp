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
    int m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(n);
    for(int i =0; i<n; i++){
        cin>>a[i];
    }

    for(int i = 0;i<n; i++){
        cin>>b[i];
    }
    int xx = -1;
    vector<int> last(n);
    last[n-1] = -1;
    if(b[n-1] > a[n-1]) xx = n-1;

    for(int i = n-2; i>=0; i--){
        // debug(i);
        // debug(xx);
        last[i] = xx;
        if(b[i] > a[i]) xx = i;
    }

   // print(last);

    //dp[i] = i tak pahuchne ka min cost

    vector<int> sfx(n);
    sfx[n-1] = b[n-1];
    for(int i = n-2; i>=0 ; i--){
        sfx[i] = sfx[i+1] + b[i];
    }

    //print(sfx);
    vector<int> dp(n+1);

    dp[n] = 0;

    dp[n-1] = a[n-1];

    for(int i = n-2; i>=0; i--){
        int direct = a[i] + sfx[i+1];
        // debug(i);
        // debug(direct);
        int ll = last[i];
        int yy;
        int zz;
        if(last[i] != -1) {
            yy = dp[last[i]];
            zz = sfx[last[i]];
        }
        else {
            yy = 1e15;
            zz = 1e15;
        }
        int indirect = a[i] + yy + sfx[i+1] - zz;
        //debug(indirect);
        dp[i] = min(direct, indirect);
    }

    int ans = 1e15;
    for(int i = 0; i<m; i++){
        ans = min(ans, dp[i]);
    }

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

