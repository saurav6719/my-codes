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
int dp[501][501];

int f(int i,  int kremaining, vector<int>&cc, vector<int> &speed, int n){

    if(i>=n){
        return 0;
    }

    if(dp[i][kremaining] != -1) return dp[i][kremaining];

    int ans1 = 1e15;

    for(int j = 0; j<=kremaining; j++){
        if(i+j+1 <= n){
            ans1 = min(ans1, (f(i+j+1, kremaining - j, cc, speed, n) + ((cc[i+j+1] - cc[i]) * speed[i])));
        }
    }

    return dp[i][kremaining] = ans1;
}
void solve(){
    int n,l,k;
    cin>>n>>l>>k;
    vector<int> cc(n+5);
    vector<int> speed(n+5);
    set<int> st;

    for(int i = 0; i<n; i++){
        cin>>cc[i];
        st.insert(cc[i]);
    }
    for(int i = 0; i<n; i++){
        cin>>speed[i];
    }
    cc[n] = l;
    speed[n] = -1e9;
    memset(dp, -1, sizeof dp);

    cout<<f(0,k, cc, speed, n);




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

