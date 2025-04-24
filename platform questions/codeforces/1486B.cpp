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

    vector<int> x;
    vector<int> y;

    for(int i = 0; i<n; i++){
        int elei;
        cin>>elei;
        int elej;
        cin>>elej;
        x.push_back(elei);
        y.push_back(elej);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    print(x);
    print(y);

    int ans1;
    int ans2;

    if(n & 1){
        ans1 = 1;
        ans2 = 1;
    }
    else{
        ans1 = x[n/2] - x[n/2 - 1] +1;
        ans2 = y[n/2] - y[n/2 - 1] +1;
    }

    debug(ans1);
    debug(ans2);

    cout<<ans1*ans2<<endl;



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

