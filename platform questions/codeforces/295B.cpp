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
    int n;cin>>n;
    vector<vector<int> > direct(n+1, vector<int> (n+1));

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin>>direct[i][j];
        }
    }

    vector<vector<int> > dp(n+1, vector<int> (n+1, 1e15));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i==j) dp[i][j] = 0;
        }
    }

    vector<int> alive(n+1, 0);
    vector<int> order(n+1);
    for(int i = 1; i<=n; i++){
        cin>>order[i];
    }

    vector<int> ans;

    // reverse(order.begin(), order.end());

    for(int i = n; i>=1; i--){
        int curradded = order[i];
        alive[curradded] = 1;

        for(int x = 1; x<=n; x++){
            if(alive[x] == 0) continue;
            dp[x][curradded] = direct[x][curradded];
            dp[curradded][x] = direct[curradded][x];
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(alive[i] == 0 or alive[j] == 0) continue;
                dp[curradded][i] = min(dp[curradded][i] , dp[curradded][j] + dp[j][i]);
                dp[i][curradded] = min(dp[i][curradded] , dp[i][j] + dp[j][curradded]);
            }
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(alive[i] == 0 or alive[j] == 0)continue;
                dp[i][j] = min(dp[i][j] , dp[i][curradded] + dp[curradded][j]);
            }
        }
        
        int sum = 0;
        for(int i= 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(alive[i] == 0 or alive[j] == 0) continue;
                sum += dp[i][j];
            }
        }

        ans.push_back(sum);
    }

    reverse(ans.begin(), ans.end());
    for(auto ele : ans){
        cout<<ele<<" ";
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

