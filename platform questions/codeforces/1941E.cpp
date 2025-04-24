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

int f(int d, int m, vector<vector<int> > &graph, int row){
    vector<int> dp(m+1, 0);
    debug(dp.size());
    debug(m);
    
    dp[m-1] = 1;
    multiset<int> mp;
    int aa = dp[m-1];

    mp.insert(aa);
    // debug(mp.size());
    for(int i = m-2; i>=0; i--){
        // debug(mp.size());
        auto ele = *mp.begin();
        int ff = ele;
        debug(ele);
        int xx = ff+ 1ll + graph[row][i];
        debug(xx);
        debug(i);
        dp[i] = xx;
        int bb = dp[i];
        mp.insert(bb);
        if(i+d+1 < m){
            int cc = dp[i+d+1];
            auto it = mp.find(cc);
            mp.erase(it);
        }
    }

    return dp[0];
}
void solve(){
    int n,m,k,d;
    cin>>n>>m>>k>>d;
    vector<vector<int> > graph(n , vector<int> (m));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>graph[i][j];
        }
    }

    vector <int> ans(n);
    debug(m);

    for(int i = 0; i<n; i++){
        ans[i] = f(d,m,graph, i);
    }

    print(ans);

    int res = INT_MAX;
    vector<int> prf;
    prf.push_back(ans[0]);

    for(int i =1; i<n; i++){
        prf.push_back(prf[i-1] + ans[i]);
    }

    res = prf[k-1];
    debug(res);
    int i = k;
    while(i < n){
        debug(prf[i]);
        res = min(res , prf[i] - ((i-k >= 0) ? prf[i-k] : 0));
        debug(res);
        i++;
    }

    cout<<res<<endl;


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
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

