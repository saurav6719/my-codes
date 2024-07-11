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
    int k;
    cin>>n>>k;
    string str;
    cin>>str;
    string final;

    vector<string> ans;

    if(n<k){
        while(n<k){
            str+= str;
            n = str.size();
        }
    }



    
 
    for(int i = 0; i<k; i++){
        final = str.substr(0, i+1);
        print(final);
        int len = final.size();
         while(len < k){
            final += final;
            len = final.size();
        }
        ans.push_back(final.substr(0,k));
    }


    sort(ans.begin(), ans.end());

    cout<<ans[0]<<endl;
 
    









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

