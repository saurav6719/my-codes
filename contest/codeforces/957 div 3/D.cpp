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

bool f(string &str, int i, int m, int k, int curr){
    if(i >= str.size()) {
        debug(i);
        debug(str.size());
        return true;
    }
    if(i>=0 and i < str.size() and str[i] == 'C') return false;
    if(curr > k) return false;
    for(int j = 1; j<=m; j++){
        int res = f(str, i+j, m, k, (i+j>= 0 and i+j<str.size() and  str[i+j] == 'W') ? curr + 1 : curr);
        if(res == true) {
            debug(i+j);
        }
    }

    return false;
}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    string str;
    cin>>str;
    print(str);

    if(f(str,-1, m, k, 0)) {
        cout<<"YES"<<endl;return;
    }
    cout<<"NO"<<endl;
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

