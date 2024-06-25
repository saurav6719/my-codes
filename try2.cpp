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
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define ll long long int 
using namespace std;

/* write core logic here */
void solve(){
    
    ll x, y, k; cin >> x >> y >> k;
 
    if(y == 2){
        if(x % 2 == 0){
            k--;
            x++;
        }
        
        while(x != 1 && k > 0){
            x++;
            k--;
            x /= 2; 
        }
        cout << x << endl;
        return;
    }
 
    while(k > 0 && x != 1){
        ll diff = x%y;
        ll more = y - diff;
 
        if(k < more){
            cout << x + k << endl;
            return;
        }
 
        k -= more;
        x += more;
        while(x % y == 0){
            x /= y;
        }
    }
 
    if(x == 1){
        // cout << "CHECK" << endl;
        if(k > 0){
            x = 1 + (k % (y - 1));
        }
    }
 
    cout << x << endl;

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

