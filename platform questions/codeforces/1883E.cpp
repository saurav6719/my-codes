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
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)

#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
bool ispower(int n){
    return __builtin_popcount(n) == 1;
}
void solve(){
    int n;cin>>n;
    vector<int> input(n);
    for(int i = 0 ; i<n; i++){
        cin>>input[i];
    }

    vector<int> dp(n,0);
    int ans = 0;
    for(int i = 1; i<n; i++){
        int badabatachota = max(input[i-1] , input[i]) / min(input[i-1], input[i]);
        int log = log2(badabatachota);
        debug(i);
        debug(log);
        if(input[i] > input[i-1]){
            dp[i] = dp[i-1] - log;
            if(dp[i] <0 ) dp[i] = 0;
        }
        else{
            int xx = max(input[i-1] , input[i]) / min(input[i-1], input[i]);
            debug(xx);
            int yy = max(input[i-1] , input[i]) % min(input[i-1], input[i]);
            debug(yy);

            if(yy==0){
                if(ispower(xx)){
                    dp[i] = log + dp[i-1];
                    continue;
                }
            }
            dp[i] = dp[i-1]+log+1;
        }
        debug(dp[i]);
    }

    for(int i = 0; i<n; i++){
        ans+= dp[i];
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
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

