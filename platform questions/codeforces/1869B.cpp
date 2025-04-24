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
    int n,k,a,b;
    cin>>n>>k>>a>>b;
    vector<pair<int,int> > input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i].first>>input[i].second;
    }
    int direct = abs(input[a-1].first - input[b-1].first) + abs(input[a-1].second - input[b-1].second);
    if(k==0) {
        cout<<direct<<endl;
        return;
    }

    int a_close = abs(input[a-1].first - input[0].first) + abs(input[a-1].second - input[0].second);
    int idx_aclose = -1;
    int b_close = abs(input[b-1].first - input[0].first) + abs(input[b-1].second - input[0].second);
    int idx_bclose = -1;
    for(int i = 0; i<k; i++){
        int aa = abs(input[a-1].first - input[i].first)+abs(input[a-1].second - input[i].second);
        if(aa < a_close) {
            a_close = aa;
            idx_aclose = i;
        }
        int bb = abs(input[b-1].first - input[i].first)+abs(input[b-1].second - input[i].second);
        debug(bb);
        if(bb < b_close) {
            b_close = bb;
            idx_bclose = i;
        }
    }
    
    debug(a_close);
    debug(b_close);
    debug(direct);
    cout<<min(direct , a_close + b_close)<<endl;
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

