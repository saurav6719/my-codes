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
int dp[105][1005];
int f(int i, int n, vector<int> &s, vector<int> &l, int total){

    if(n==0) return 1;

    if(dp[i][n] != -1) return dp[i][n];


    int ans = 0;

    // i pe short 

    int ipeshort = s[i];
    debug(ipeshort);

    int ipelong = l[i];
    debug(ipelong);
    
    for(int j = 1; j<=total; j++){
        // debug(i);
        // debug(j);
        ans += (ipeshort * (s[j] + l[j]) * f(j, n-1, s, l, total));
        ans %= mod;

        debug(ans);
        
        // debug(ans);
        ans += (ipelong * (s[j]) * f(j, n-1, s, l, total));
        ans %= mod;
        // debug(i);
        // debug(j);
        debug(ans);
    }

    return dp[i][n] =  ans;


}
void solve(){
    int m;cin>>m;
    int n;
    cin>>n;

    vector<int> s(m+1);
    vector<int> l(m+1);

    for(int i = 1; i<=m; i++){
        cin>>s[i];
    }
    for(int i = 1; i<=m; i++){
        cin>>l[i];
    }

    memset(dp, -1, sizeof dp);



    // for(int i = 1; i<=m; i++){
    //     cout<<s[i]<<" ";
    // }
    // cout<<endl;
    // for(int i = 1; i<=m; i++){
    //     cout<<l[i]<<" ";
    // }
    // cout<<endl;

    cout<<f(1, n, s, l, m);

    // debug(f(1, 1, s, l , 3));



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

