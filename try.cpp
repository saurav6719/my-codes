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
    vector<vector<char>> grid(n+1, vector<char>(n+1));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>grid[i][j];
        }
    }
    map<int,int> mp;
    int i = 1; int j= n;
    while(i<j){
        mp[i] = j;
        mp[j] = i;
        i++;
        j--;
    }

    vector<vector<vector<pp> > > dp(n+1, vector<vector<pp>>(n+1, vector<pp>()));

    for(int i = 1; i<=n; i++){
        for(int j = 1 ; j<=n; j++){
            int transitionx = mp[j];
            int transitiony = i;
            debug(i);
            debug(j);
            dp[i][j].push_back({i,j});
            while(transitionx != i or transitiony != j){
                debug(transitionx);
                debug(transitiony);
                dp[i][j].push_back({transitionx, transitiony});

                int transitionxcopy = transitionx;
                int transitionycopy = transitiony;
                transitionx = mp[transitionycopy];
                transitiony = transitionxcopy;
                // dp[i][j].push_back({transitionx, transitiony});
            }
        }
    }

    // for(int k = 0; k<dp[5][5].size(); k++){
    //     cout<<dp[5][5][k].first<<" "<<dp[5][5][k].second<<endl;
    // }

    // for(int i = 1; i<=n; i++){
    //     for(int j = 1; j<=n; j++){
    //         debug(i);
    //         debug(j);
    //         for(int k = 0; k<dp[i][j].size(); k++){

    //             cout<<dp[i][j][k].first<<" "<<dp[i][j][k].second<<endl;
    //         }
    //     }
    // }

    vector<vector<char>> gridcopy = grid;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            int affectivex = mp[j];
            int effectivey = i;
            debug(i);
            debug(j);
            debug(affectivex);
            debug(effectivey);
            int aaa = affectivex;
            int bbb = n+1-effectivey;
            int ccc = n+1-affectivex;
            int ddd = effectivey;
            int nooftransitions = min(aaa,bbb);
            nooftransitions = min(nooftransitions, ccc);
            nooftransitions = min(nooftransitions, ddd);
            debug(nooftransitions);
            pp xx = dp[i][j][(nooftransitions % dp[i][j].size())];
            int x = xx.first;
            int y = xx.second;
            debug(x);
            debug(y);
            gridcopy[i][j] = grid[x][y];
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cout<<gridcopy[i][j];
        }
        cout<<endl;
    }


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

