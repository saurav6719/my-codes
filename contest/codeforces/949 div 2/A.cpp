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

unsigned int closestPowerOfTwoLessThan(unsigned int n) {
    // If n is zero, there's no power of two less than 0.
    if (n == 0) return 0;

    // Initialize result to 1 (2^0).
    unsigned int result = 1;

    // Shift left until result is less than n.
    while (result <= n) {
        result <<= 1;
    }

    // Shift right once to get the closest power of two less than n.
    return result >> 1;
}


unsigned int log2(unsigned int n) {
    if (n == 0) return -1; // Logarithm of zero is undefined

    unsigned int log = 0;
    while (n >>= 1) {
        log++;
    }
    return log;
}


void solve(){
    
    int l;
    cin>>l;
    int r;
    cin>>r;
    int xx = closestPowerOfTwoLessThan(r);
    
        cout<< log2(xx)<<endl;;
    



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

