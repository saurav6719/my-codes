/**
 *    author: Saurav
 *    created: 2024.10.18 02:26:18
 **/

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
vector<vector<int> > dp;
int f(int i, int j, vector<int> &height, vector<int> &cost, int n){
    if(i==n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int lastheight = (i==0 ? 0 :height[i-1]+ j);

    int ans = 1e16;

    for(int k = 0; k<=10; k++){
        if(height[i] + k == lastheight) continue;
        ans = min(ans, cost[i] * k + f(i+1, k, height, cost, n));
    }

    return dp[i][j] = ans;
}
void solve(){
    int n;
    cin>>n;
    vector<int> height(n);
    vector<int> cost(n);
    for(int i= 0; i<n; i++){
        cin>>height[i]>>cost[i];
    }
    dp.clear();
    dp.resize(n+1, vector<int> (11, -1));
    int ans = 1e16;
    ans = min(ans , f(0,0,height,cost,n));
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

