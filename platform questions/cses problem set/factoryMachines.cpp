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

bool poss(int time, vector<int> & input, int t){
    int pro = 0;
    for(int i = 0; i<input.size(); i++){
        int xx = time / input[i];
        //debug(xx);
        pro += xx; 
        if(pro >= t) return true;
        //debug(pro);
    }
    return pro >= t;
}
void solve(){
    int n;
    cin>>n;
    int t;
    cin>>t;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    sort(input.begin(), input.end());
    print(input);
    

    int lo = 0;
    int hi = t * input[n-1];
    debug(hi);
    int res = -1;
    while(lo<=hi){
        int mid = lo +(hi-lo)/2;
        debug(mid);
        if(poss(mid, input,t)){
            res = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    cout<<res;

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

