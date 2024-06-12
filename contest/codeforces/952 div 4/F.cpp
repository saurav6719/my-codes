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

bool poss(int mid, vector<int> &damage, vector<int> &cooldown, int h){
    int cnt = 0;
    for(int i = 0; i<damage.size(); i++){
        cnt += (1+((mid-1)/cooldown[i])) * damage[i];
        if(cnt >= h ) return true;
    }

    if(cnt >= h) return true;
    return false;
}
void solve(){
    int h,n;
    cin>>h>>n;
    vector<int> damage(n);
    for(int i = 0; i<n; i++){
        cin>>damage[i];
    }
    vector<int> cooldown(n);
    for(int i = 0; i<n; i++){
        cin>>cooldown[i];
    }

    int lo = 1;
    int hi = 1e12;
    int res = -1;

    while(lo<=hi){
        int mid = lo + (hi - lo )/2;
        // debug(mid);
        // debug(poss(mid, damage, cooldown, h));
        if(poss(mid, damage, cooldown, h)){
            res = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }

    cout<<res<<endl;


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

