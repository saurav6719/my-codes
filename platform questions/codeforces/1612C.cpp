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

bool poss(int mid, int k, int x, bool check ){

    if(mid <= k){
        int res = mid * (mid+1)/2;
        if(res < x) return true;
        return false;
    }
    int res = k * (k+1)/2;
    if(mid > k){
        int xx = mid - k;
        int sub = xx * (xx+1)/2;
        res += xx * k;
        res -= sub;
    }
    if(res < x) return true;
    return false;
}

void solve(){
    int k;
    cin>>k;
    int x;
    cin>>x;
    int lo =0;
    int hi = 2*k-1;
    int res = -1;
    bool check = false;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(poss(mid,k,x,check)){
            //debug(mid);
            res = mid;
            lo = mid+1;
        }
        else hi = mid -1;
    }
    if(res >= 2*k-1){
        res = 2*k-1;
        cout<<res<<endl;
        return;
    }
    cout<<res+1<<endl;
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

