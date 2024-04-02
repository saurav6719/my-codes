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
    int n;
    cin>>n;
    vector<int> input(n);
    bool odd = true;
    bool even = true;
    int k;
    for(int i = 0; i<n; i++){
        cin>>input[i];
        if(input[i] & 1) even = false;
        else odd = false;
    }
    if(!even and !odd){
        //even odd dono 
        k = 2;
    }
    else{
        int ans = 4;
        set<int> mods;
        int cnt = 0;
        while(mods.size() != 2){
            cnt++;
            mods.clear();
            for(int i = 0 ; i<n; i++){
                mods.insert(input[i] % ans);
            }
            if(mods.size() == 2) {
                k = ans;
                break;
            }
            ans *= 2;
        }
        debug(cnt);
    }

    cout<<k<<endl;
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

