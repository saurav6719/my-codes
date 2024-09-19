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
    int m,x;
    cin>>m>>x;
    vector<int> c(m);
    vector<int> h(m);
    for(int i = 0; i<m; i++){
        cin>>c[i]>>h[i];
    }

    int maxi = accumulate(h.begin(), h.end(), 0);

    int dp[m+1][maxi+1];

    for(int i = 0; i<=maxi; i++){
        if(i==0) dp[0][i] = 0;
        else dp[0][i] = -1e15;
    }

    if(c[0] == 0){
        dp[0][h[0]] = 0;
    }

    debug(h[1]);

    for(int i = 1; i<m; i++){
        for(int j = 0; j<=maxi; j++){
            int aa = dp[i-1][j] + x;
            if(dp[i-1][j] < 0) aa = -1e15;
            int bb ;
            if(j-h[i] >= 0) {
                bb= dp[i-1][j-h[i]] + x - c[i];
                if(dp[i-1][j-h[i]] < 0) bb = -1e15;
            }
            else bb = -1e15;
            dp[i][j] = max(aa , bb);
        }
    }
    int ans = 0;

    // cout<<dp[1][10]<<endl;

    debug(dp[1][1]);

    for(int i = 0; i<=maxi; i++){
        if(dp[m-1][i] >= 0) ans = i;
    }

    // for(int i = 0; i<m; i++){
    //     for(int j = 0; j<=maxi; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }



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

