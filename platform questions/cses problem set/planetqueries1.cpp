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
//#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
void solve(){
    int n, q;
    scanf("%d %d", &n, &q);
    int boss[200005][31];
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &boss[i][0]);
    }

    int limit = 31;

    for (int k = 1; k < limit; k++) {
        for (int i = 1; i <= n; i++) {
            boss[i][k] = boss[boss[i][k - 1]][k - 1];
        }
    }

    for(int Q= 0; Q<q; Q++) {
        int x, k;
        scanf("%d %d", &x, &k);
        for(int i = 0; i<limit; i++){
            if((k &(1<<i))){
                x = boss[x][i];
            }
        }
        printf("%d\n", x);
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
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
