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
double dp[305][305][305];
double f(int c1, int c2, int c3, int n){
    if(c1 == 0 and c2 == 0 and c3 == 0) return 0.0;
    // cout<<"c1 "<<c1<<endl;
    // cout<<"c2 "<<c2<<endl;
    // cout<<"c3 "<<c3<<endl;
    if(dp[c1][c2][c3] > -0.9) return dp[c1][c2][c3];

    double ans = 1;
    if(c1 > 0) ans += (f(c1-1, c2, c3, n)) * ((1.0 * c1 / n));

    if(c2 > 0) ans += 1.0 * c2 / n * f(c1+1 , c2-1, c3, n);

    if(c3 > 0) ans += 1.0 * c3 / n * f(c1, c2+1, c3-1, n);

    double p0 = 1.0 * (n - c1- c2-c3) / n;

    

    ans /= 1.0 - p0;

    return dp[c1][c2][c3] = ans;
}
void solve(){
    int n;
    cin>>n;
    debug(n);
    vector<int> cnt(4,0);
    memset(dp, -1, sizeof dp);

    for(int i = 0; i<n; i++){
        int a;

        cin>>a;
        debug(a);
        cnt[a]++;
    }
    print(cnt);

    cout<<fixed<<setprecision(10)<<f(cnt[1] , cnt[2] , cnt[3], n);
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

