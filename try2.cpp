/**
 *    author: Saurav
 *    created: 2025.05.01 05:23:43
 *    We stop at Candidate Master in 2025
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

#define printset(s) do { \
    cout << "set-- starts" << endl; \
    for (auto it = s.begin(); it != s.end(); ++it) { \
        cout << *it << endl; \
    } \
    cout << "set-- ends" << endl; \
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
#define MOD 1000000007
#define mod_add(a, b) (((a) % MOD + (b) % MOD) % MOD)
#define mod_sub(a, b) ((((a) % MOD - (b) % MOD) + MOD) % MOD)
#define mod_mul(a, b) (((1LL * (a) % MOD) * (b) % MOD) % MOD)
#define int long long int
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
class SCC {
    int n;
    vector<vector<int>> adj, rev_adj;
    vector<bool> visited;
    stack<int> order;
    vector<vector<int>> sccs;

    void dfs1(int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v])
                dfs1(v);
        }
        order.push(u);
    }

    void dfs2(int u, vector<int>& component) {
        visited[u] = true;
        component.push_back(u);
        for (int v : rev_adj[u]) {
            if (!visited[v])
                dfs2(v, component);
        }
    }

public:
    SCC(int nodes, const vector<vector<int>>& edges) {
        n = nodes;
        adj.resize(n + 1);
        rev_adj.resize(n + 1);
        visited.assign(n + 1, false);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            rev_adj[v].push_back(u);
        }
    }

    vector<vector<int>> getSCCs() {
        // First pass: normal DFS to fill order
        for (int i = 1; i <= n; ++i) {
            if (!visited[i])
                dfs1(i);
        }

        // Second pass: DFS on reversed graph
        fill(visited.begin(), visited.end(), false);
        while (!order.empty()) {
            int u = order.top();
            order.pop();
            if (!visited[u]) {
                vector<int> component;
                dfs2(u, component);
                sccs.push_back(component);
            }
        }

        return sccs;
    }
};


pp f(vector<vector<int> > &graph, map<int,int> &sccsize, map<int,int> &sccvalue, int u, vector<pp> &dp){
    int currsize = sccsize[u];
    int currvalue = sccvalue[u];
    if(dp[u].first != 0){
        return dp[u];
    }

    for(auto ele : graph[u]){
        pp temp = f(graph, sccsize, sccvalue, ele, dp);
        if(temp.first + currsize > dp[u].first){
            dp[u].first = temp.first + currsize;
            dp[u].second = temp.second + currvalue;
        }
        else if(temp.first + currsize == dp[u].first){
            dp[u].second = min(dp[u].second, temp.second + currvalue);
        }
    }

    if(dp[u].first == 0){
        dp[u].first = currsize;
        dp[u].second = currvalue;
    }
    return dp[u];
}
void solve(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> values(n+1);
    for(int i = 1; i <= n; i++){
        cin>>values[i];
    }

    vector<vector<int> > edges;
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        edges.push_back({u, v});
    }

    SCC scc(n, edges);
    vector<vector<int>> sccs = scc.getSCCs();

    print2d(sccs);

    map<int,int> originaltoscc;
    map<int,int> sccvalue;
    map<int,int> sccsize;
    for(int i = 0; i<sccs.size(); i++){
        int sccsum = 0;
        int sccsz = 0;
        for(int j = 0; j < sccs[i].size(); j++){
            originaltoscc[sccs[i][j]] = i;
            sccsum += values[sccs[i][j]];
            sccsz++;
        }
        sccvalue[i] = sccsum;
        sccsize[i] = sccsz;
    }

    vector<vector<int> > newgraph(sccs.size());

    for(auto ele : edges){
        int u = ele[0];
        int v = ele[1];
        if(originaltoscc[u] != originaltoscc[v]){
            newgraph[originaltoscc[u]].push_back(originaltoscc[v]);
        }
    }

    print2d(newgraph);

    vector<pp> dp(sccs.size(), {0, 1e15});

    pp ans = {0, 1e15};

    for(int i = 0; i < sccs.size(); i++){
        pp temp = f(newgraph, sccsize, sccvalue, i, dp);
        if(temp.first > ans.first){
            ans.first = temp.first;
            ans.second = temp.second;
        }
        else if(temp.first == ans.first){
            ans.second = min(ans.second, temp.second);
        }
    }
    cout<<ans.first<<" "<<ans.second<<endl;
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

