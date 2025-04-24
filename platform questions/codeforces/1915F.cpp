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
    vector<int> start(n);
    vector<int> end(n);
    vector<pair<int, int> > pairr(n);
    for(int i = 0; i<n; i++){
        cin>>start[i];
        cin>>end[i];
        pairr[i].first = start[i];
        pairr[i].second = end[i];
    }
    sort(pairr.begin(), pairr.end());
    sort(end.begin(), end.end());

    int ans = 0;
    for(int i = 0; i<n; i++){
        int curr = pairr[i].second;
        //debug(curr);
        int res = lower_bound(end.begin(), end.end(), curr) - end.begin();
        ans += res;
        end.erase(end.begin() + res);
        //debug(ans);
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

