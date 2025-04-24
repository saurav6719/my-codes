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
    int n,c;
    cin>>n>>c;


    vector<vector<int> > dp(n+5, vector<int> (2));

    dp[0][0] = 0;
    dp[0][1] = 0;

    cout<<0<<" ";
    vector<int> a(n+5);
    for(int i= 1; i<n; i++){
        cin>>a[i];
    }

    vector<int> b(n+5);
    for(int i = 1; i<n; i++){
        cin>>b[i];
    }

    print(b);

    for(int i = 1; i<n; i++){
        dp[i][0] = a[i] + min(dp[i-1][0] , dp[i-1][1]);
        dp[i][1] = min(b[i] + dp[i-1][0] +  c , b[i] + dp[i-1][1]);

        if(i==1) dp[i][1] = b[i] + dp[i-1][0] + c;

        if(i==1){
            debug(b[i]);
            debug(dp[i-1][0]);
            debug(b[i] + dp[i-1][0] +  c);
            debug(b[i] + dp[i-1][1]);
        }
        debug(i);
        debug(dp[i][0]);
        debug(dp[i][1]);

        cout<<min(dp[i][0] , dp[i][1])<<" ";
    }

    cout<<endl;
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

