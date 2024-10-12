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
int n;

int dp2[3001][3001];

int f(int idx,int lastpinned,  vector<pp> &positioncost, vector<vector<int> > &dp){


    if(idx == 0){
        return positioncost[0].second + dp[0][lastpinned]; 
    }

    if(dp2[idx][lastpinned] != -1) return dp2[idx][lastpinned];


    int ans = 1e15;

    // not pin it 

    ans = min(ans , f(idx-1, lastpinned  , positioncost , dp));

    // pin it

    ans = min(ans , f(idx -1 , idx , positioncost , dp ) + positioncost[idx].second + dp[idx][lastpinned]);

    return dp2[idx][lastpinned] = ans;

}
void solve(){
    cin>>n;
    vector<pp> positioncost(n);
    for(int i=0;i<n;i++){
        int x, c;
        cin>>x>>c;
        positioncost[i] = {x,c};
    }
    sort(positioncost.begin(), positioncost.end());

    memset(dp2, -1, sizeof dp2);

    vector<vector<int> > dp(n+1, vector<int> (n+1, 0));

    
    for(int i = n-1; i>=0; i--){
        for(int j = n; j>=i; j--){
            if(i==j) dp[i][j] = 0;
            else dp[i][j] = dp[i+1][j] + (j-i-1)*abs(positioncost[i].first - positioncost[i+1].first);
        }
    }

    cout<<f(n-1, n, positioncost, dp)<<endl;

    // print2d(dp);
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

