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
int dp[100005][16];
int f(string &str, int mask, int idx, vector<int> &cost){
    if(mask == 15) return 1e17;
    if(idx == str.size()) return 0;

    if(dp[idx][mask] != -1) return dp[idx][mask];
    int ans = 1e17;
    //remove it 
    ans = min(ans, cost[idx] + f(str, mask, idx+1, cost));

    //keep it 
    if(str[idx] == 'h'){
        ans = min(ans, f(str, (mask|1) , idx+1, cost));
    }

    else if(str[idx] == 'a'){
        if((mask & 1) == 1){
            ans = min(ans, f(str, (mask | 2), idx+1, cost));
        }
        else{
            ans = min(ans , f(str, mask, idx+1, cost));
        }
    }

    else if(str[idx] == 'r'){
        if((mask & 3) == 3){
            ans = min(ans, f(str, (mask | 4), idx+1, cost));
        }
        else{
            ans = min(ans , f(str, mask, idx+1, cost));
        }
    }

    else if(str[idx] == 'd'){
        if((mask & 7 )== 7){
            ans = min(ans, f(str, (mask | 8), idx+1, cost));
        }
        else{
            ans = min(ans , f(str, mask, idx+1, cost));
        }
    }

    else ans= min(ans, f(str, mask, idx+1, cost));


    return dp[idx][mask] = ans;

}
void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;

    memset(dp, -1, sizeof dp);
    vector<int> cost(n);
    for(int i = 0; i<n; i++){
        cin>>cost[i];
    }

    cout<<f(str, 0,0,cost);




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

