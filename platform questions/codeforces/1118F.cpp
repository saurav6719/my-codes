/**
 *    author: Saurav
 *    created: 2024.10.22 23:49:15
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
map<int,pp> dp;

pp dfs(vector<vector<int> > &tree, int node, int par, vector<int> &color){
    int blue = 0;
    int red = 0;
    if(color[node] == 1) red++;
    else if(color[node] == 2) blue++;

    for(auto child : tree[node]){
        if(child == par) continue;
        auto temp = dfs(tree, child, node, color);
        red += temp.first;
        blue += temp.second;
    }

    return dp[node] = {red, blue};
}
vector<int> parent;
void dfs2(vector<vector<int> > &tree, int node, int par){
    parent[node] = par;
    for(auto child : tree[node]){
        if(child == par) continue;
        dfs2(tree, child, node);
    }
}

void solve(){
    int n;
    cin>>n;

    vector<int> color(n+1);

    int totalred= 0, totalblue = 0;

    for(int i = 1; i<=n; i++){
        cin>>color[i];
        if(color[i] == 1) totalred++;
        else if(color[i] == 2) totalblue++;
    }

    vector<vector<int>> tree(n+1);
    parent.assign(n+1, 0);
    vector<pp> edgelist;
    for(int i = 1; i<n; i++){
        int u, v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        edgelist.push_back({u,v});
    }

    dfs2(tree, 1, 0);

    pp xx = dfs(tree, 1, 0, color);

    int ans = 0;
    for(auto ele : edgelist){
        int u = ele.first;
        int v = ele.second;
        if(parent[u] == v){
            swap(u,v);
        }

        int red = dp[v].first;
        int blue = dp[v].second;

        int remainingred = totalred - red;
        int remainingblue = totalblue - blue;

        if(red == 0 and remainingblue == 0  or blue == 0 and remainingred == 0){
            ans ++;
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

