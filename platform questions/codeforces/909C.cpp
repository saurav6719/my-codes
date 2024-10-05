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
void solve(){
    int n;
    cin>>n;
    vector<char> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    vector<vector<int> > dp(n+1, vector<int> (n+1, 0));
    for(int j = 0; j<n; j++){
        dp[n][j] = 1;
    }
    for(int i = n-1; i>=1; i--){
        vector<int> temp = dp[i+1];
        for(int i = 1; i<temp.size(); i++){
            temp[i]+= temp[i-1];
            temp[i] %= mod;
        }
        if(input[i-1] == 'f'){
            for(int j = 0; j<n; j++){
                if(input[i] == 'f'){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        else{
            for(int j = 0; j<n; j++){
                if(input[i] == 's') dp[i][j] = temp[j];
                else{
                    dp[i][j] = (temp[j+1] % mod  - temp[0] % mod + mod)%mod ;
                    
                }
            }
        }
    }
    print2d(dp);
    if(input[0] == 's'){
        cout<<dp[1][0];
    }
    else cout<<dp[1][1];
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

