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
#define mod 1000000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
int power(int a, int x, int p = mod){
    //finding a to the power x
    int res = 1;
    a = a % p;
    while(x>0){
        if(x & 1){
            res = (res * a) % p;
        }
        x = x >> 1;
        a = (a * a) % p;
    }
    return res;

}

//link -> https://codeforces.com/gym/302977/problem/A
void solve(){
    int n;
    cin>>n;
    if(n&1){
        cout<<0;
        return;
    }
    int prev = 2;
    for(int i = 4;i<=n; i+=2){
        int curr = 1;
        curr = 2 * prev;
        prev = curr;
    }
    cout<<prev;
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

