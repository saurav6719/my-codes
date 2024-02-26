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
long double root (long double x){
    long double lo = 0;
    long double hi = x+1;
    while(lo<hi){
        long double mid = lo+(hi - lo)/2;
        if (abs(mid * mid - x) < 1e-9) return mid;
        else if (mid * mid < x) lo = mid;
        else hi = mid;
    }
}

long double f(long double mid){
    long double res = mid * mid;
    res += root(mid);
    return res;
}
void solve(){
    long double c;
    cin>>c;

    long double lo = (long double)0.0 ;
    long double hi = (long double)1e10;
    int count = 0;
    long double ans;
    while(count < 200){
        long double mid = lo+(hi-lo)/(long double) 2;
        
        if((mid * (long double) mid + (long double) sqrt(mid)) < c){
            lo = mid;
        }
        else{
            hi = mid;
            ans = mid;
        }
        count ++;
    }

    cout<<fixed<<setprecision(12)<<ans<<"\n";

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

