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
    map<int,int> v;
    for(int i= 0; i<n; i++){
        cin>>input[i];
        v[input[i]]++;
    }
    debug(v[1]);
    int ans ;
    bool check = false;
    if(v[0] == 1) check = true;
    if(v[0] == 0){
        ans = 0;
        cout<<ans<<endl;
        return;
    }

    int cnt = 1;
    while(true){
        if(v.count(cnt) == 0){
            cout<<cnt<<endl;
            return;
        }
        else if(v[cnt] == 1 and check == true){
            cout<<cnt<<endl;
            return;
        }
        else if(v[cnt] == 1 and check == false){
            check = true;
        }
        cnt++;
    }

    cout<<ans<<endl;
    return;

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

