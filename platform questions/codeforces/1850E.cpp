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
    int n,c;
    cin>>n>>c;
    vector<int> sze(n);
    for(int i = 0; i<n; i++){
        cin>>sze[i];
    }
    int res = -1;
    int lo = 0;
    int hi = 1e9;


    while(lo <= hi){
        int mid = lo + (hi-lo) /2;
        // debug(lo);
        // debug(hi);
        // debug(mid);
        int rs = 0;
        for(int i = 0;i<n; i++){
            int aa = 0;
            aa += sze[i];
            aa += mid;
            aa += mid;
            aa *= aa;
            rs += aa; 
            if(rs > c) break; 
        }   
        //debug(rs);
        
        if(rs == c) {
            cout<<mid<<endl;
            return;
        }
        else if(rs < c){
            lo = mid + 1;
        }
        else hi = mid - 1;
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

