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
    string str;
    cin>>str;
    int cnt1 = 0;
    for(int i = 0; i<n; i++){
        if(str[i] == '1') cnt1++;
    }
    if(cnt1 & 1){
        cout<<"NO"<<endl;
        return;
    }
    else{
        if(cnt1 == 2){
            int ff = -1;
            int ss = -1;
            for(int i = 0; i<n; i++){
                if(str[i] == '1'){
                    if(ff==-1) ff = i;
                    else ss = i;
                } 
            }
            if(abs(ff-ss) == 1){
                cout<<"NO"<<endl;
                return;
            }
            else {
                cout<<"YES"<<endl;
                return;
            }
        }
        else {
            cout<<"YES"<<endl;
            return;
        }

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

