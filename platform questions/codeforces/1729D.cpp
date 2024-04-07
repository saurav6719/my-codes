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
    vector<int> x(n);
    vector<int> y(n);
    for(int i = 0; i<n; i++){
        cin>>x[i];
    }
    for(int i = 0; i<n; i++){
        cin>>y[i];
    }
    print(x);
    print(y);

    vector<int>diff(n);
    for(int i = 0; i<n; i++){
        diff[i] = y[i] - x[i];
    }

    sort(diff.begin(), diff.end());
    print(diff);

    int a = 0;
    int b = n-1;
    int ans = 0;

    while(a<b){
        debug(diff[a]);
        debug(diff[b]);
        if(diff[a] + diff[b] >= 0){
            ans++;
            a++;
            b--;
            continue;
        }
        else{
            a++;
            continue;
        }
    }

    cout<<ans<<endl;



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

