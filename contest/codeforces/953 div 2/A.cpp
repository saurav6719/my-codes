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
    int a;
    int b;
    cin>>n>>a>>b;
    if(a>=b){
        cout<<n*a<<endl;
        return;
    }
    int last = b-a;
    debug(last);
    if(last > n){
        int xx = b-n+1;
        int pura = b * (b+1) /2;
        int ghata = xx * (xx-1)/2;
        cout<<pura - ghata<<endl;
        return;
    }
    int ans = 0;
    if(last <= n){
        int xx = b-last;
        int pura = b*(b+1) / 2;
        int ghata = xx * (xx+1)/2;
        int bacha = n-last;
        ans += (pura - ghata);

        ans += (bacha) * a;

        cout<<ans<<endl;
        return;
    }
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

