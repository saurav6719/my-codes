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
    int q;
    cin>>n>>q;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    vector<int> minleft(n);
    vector<int> minright(n);
    minleft[0] = input[0];
    minright[n-1] = input[n-1];

    for(int i = 1; i<n; i++){
        minleft[i] = min(minleft[i-1] , input[i]);
    }

    for(int i = n-2; i>=0; i--){
        minright[i] = min(minright[i+1], input[i]);
    }

    while(q--){
        int a;
        int b;
        cin>>a>>b;
        a--;b--;

        cout<<max(minleft[b] , minright[a])<<endl;
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

