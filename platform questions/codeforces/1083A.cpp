/**
 *    author: Saurav
 *    created: 2024.10.22 17:06:27
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
vector<int> dp;

vector<vector<int> > full;
int dfs(vector<vector<pp> > &tree, int node, int par, vector<int> &fuels){
    int ans = fuels[node];

    vector<int> &v  = full[node];
    for(auto child : tree[node]){
        if(child.first == par) continue;
        int xx = dfs(tree, child.first, node, fuels) - child.second + fuels[node];
        ans = max(ans , xx);
        v.push_back(dp[child.first] - child.second);
    }

    // sort(v.rbegin(), v.rend());
    return dp[node] = ans;
}
void solve(){
    int n;
    cin>>n;
    vector<int> fuels(n+1);
    for(int i = 1 ; i<=n; i++){
        cin>>fuels[i];
    }

    full.clear();
    full.resize(n+1, vector<int> ());


    if(n==1){
        cout<<fuels[1]<<endl;
        return;
    }

    vector<vector<pp> > tree(n+1, vector<pp> ());

    dp.assign(n+1, 0);

    for(int i =1; i<n; i++){
        int u,v,w;
        cin>>u>>v>>w;
        tree[u].push_back({v,w});
        tree[v].push_back({u,w});
    }

    int xx = dfs(tree, 1, 0, fuels);
    int ans = -1e15;

    for(int i =1; i<=n; i++){
        ans = max(ans, dp[i]);
    }

    print(dp);

    for(int i = 1; i<=n; i++){
        sort(full[i].rbegin(), full[i].rend());
        if(full[i] .size() > 1){
            ans = max(ans , full[i][0] + full[i][1] + fuels[i]);
            debug(i);
            debug(full[i][0]);
            debug(full[i][1]);
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

