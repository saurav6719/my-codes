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
    int x;
    cin>>x;
    vector<int> input(n);
    multiset<int> ms;
    int sum = 0;
    for(int i = 0; i<n; i++){
        cin>>input[i];
        ms.insert(input[i]);
        sum += input[i];
    }

    debug(sum); 
    int cnt = 1;
    int left = x;

    while(left >= 0){
        if(ms.empty()) break;
        auto it = ms.upper_bound(left);
        if(it == ms.begin()){
            left = x;
            cnt++;
            continue;
        }
        it--;
        int val = *it;
        debug(val);
        debug(cnt);
        ms.erase(it);
        left -= val;
    }

    cout<<cnt;


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

