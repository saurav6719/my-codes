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

#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
const int mod = 1e9 + 7;
// Function to calculate power in modular arithmetic
long long power(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = power(a, b / 2);
    if (b % 2)
        return ((res * res)%mod * a)%mod;
    else
        return (res * res)%mod;
}

void solve(){
    int n;
    cin>>n;
    int sum = 0;
    int i = 1;
    int j;
    while(i<=n){
        int q = n/i;
        j = n/q+1;
        int ff = ((((j%mod)*((j-1)%mod))%mod) * power(2,mod-2))%mod;
        int xx = ((((i%mod)*((i-1)%mod))%mod) * power(2,mod-2))%mod;
        int aa = (ff-xx+mod)%mod;
        sum = (sum + (q%mod) * aa) % mod;
        i=j;
    }

    cout<<sum;
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

