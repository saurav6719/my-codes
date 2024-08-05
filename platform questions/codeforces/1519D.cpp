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
    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    for(int i = 0; i<n; i++){
        cin>>b[i];
    }

    vector<vector<int> > dp(5001, vector<int> (5001, 0));

    for(int i = n-1 ; i>=0; i--){
        for(int j = i; j < n; j++){

            if(i==j){
                dp[i][j] = (a[i] * b[j]);
                continue;
            }
            else if(j-i == 1){
                dp[i][j] = (a[j] * b[i]) + (a[i] * b[j]);
                continue;
            }

            else dp[i][j] = dp[i+1][j-1] + ((a[j] * b[i]) + (a[i] * b[j]));
        }
    }

    vector<int> prf;
    for(int i = 0 ; i<n; i++){
        prf.push_back(a[i] * b[i]);
    }

    for(int i = 1; i<n; i++){
        prf[i] += prf[i-1];
    }

    int ans = INT_MIN;

    for(int i= 0; i<n; i++){
        for(int j = i; j<n; j++){

            int xx = 0;
            if(i-1 >= 0) xx = prf[i-1];
            int yy = prf[n-1] - prf[j];
            ans = max(ans , dp[i][j] + xx + yy);
        }
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

