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
#define ppc pair<char,char> 
using namespace std;

/* write core logic here */
int dp[101][27][101];

int f(int idx, int k, string &str, map<ppc, int> &mp, int j){
    


    // change 

    if(k<0) return -1e17;

    if(idx == str.size()-1) return 0;


    if(dp[idx][j][k] != -1) return dp[idx][j][k];
    int ans = -1e17;

    char ch = j + 'a' - 1;

    for(int js = 1; js<=26; js++){
        char newch = js + 'a' - 1;

        if(str[idx+1] != newch){
            ans = max(ans, f(idx+1, k-1, str, mp, js) + mp[{ch, newch}]);
        }
        else{
            ans = max(ans , f(idx+1, k, str, mp, js) + mp[{ch, newch}]);
        }
    }

    return dp[idx][j][k] = ans;


}

void solve(){
    string str;
    cin>>str;
    int ks;cin>>ks;
    map<ppc, int> mp;
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        char c1,c2;
        cin>>c1>>c2;
        int val;
        cin>>val;

        mp[{c1,c2}] = val;
    }

    memset(dp, -1, sizeof dp);

    int ans = -1e17;
    for(int j = 1; j<=26; j++){
        char ch = j+'a' - 1;

        if(ch == str[0]){
            ans = max(ans , f(0, ks, str, mp, j));
        }
        else{
            ans = max(ans,f(0, ks-1, str, mp, j));
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

