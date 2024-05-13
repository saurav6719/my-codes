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
    string str;
    cin>>str;
    int n = str.size();

    string str_copy = str;
    sort(str_copy.begin(), str_copy.end());
    if(str == str_copy){
        cout<<1<<endl;
        return;
    }
    bool start = false;
    bool end = false;
    if(str[0] == '0') start=true;
    if(str[n-1] == '0') end = true;

    int seg = 0;

    for(int i = 0; i<n; i++){
        if(str[i] == '0'){
            seg ++;
            int i_copy = i;
            while(i_copy < n and str[i_copy] == '0') i_copy ++;
            i = i_copy-1;
            continue;
        }
    }
    debug(seg);
    
    int ans = seg*2;

    if(seg == 1){
        ans--;
        cout<<ans+1<<endl;
        return;
    }
    if(start) ans -= 2;
    else ans--;
    if(end) ans--;
    cout<<ans+1<<endl;

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

