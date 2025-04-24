/**
 *    author: Saurav
 *    created: 2025.02.02 01:41:56
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
class TwoSAT {
    int n;  // Number of variables
    vector<vector<int>> adj, rev_adj;
    vector<int> order, component, assignment;
    vector<bool> visited;

public:
    TwoSAT(int vars) : n(vars) {
        adj.resize(2 * n);
        rev_adj.resize(2 * n);
        assignment.resize(n, -1);
    }

    // Convert x to index in adjacency list (0-based)
    int varIndex(int x) {
        return (x > 0) ? (2 * (x - 1)) : (2 * (-x - 1) + 1);
    }

    // Add clause (x OR y)
    void addClause(int x, int y) {
        int x_idx = varIndex(x), y_idx = varIndex(y);
        int nx_idx = x_idx ^ 1, ny_idx = y_idx ^ 1;

        adj[nx_idx].push_back(y_idx); // ¬x → y
        adj[ny_idx].push_back(x_idx); // ¬y → x
        rev_adj[y_idx].push_back(nx_idx);
        rev_adj[x_idx].push_back(ny_idx);
    }

    // 1st pass DFS: Fill order stack
    void dfs1(int v) {
        visited[v] = true;
        for (int u : adj[v])
            if (!visited[u])
                dfs1(u);
        order.push_back(v);
    }

    // 2nd pass DFS: Assign SCC components
    void dfs2(int v, int comp) {
        component[v] = comp;
        for (int u : rev_adj[v])
            if (component[u] == -1)
                dfs2(u, comp);
    }

    // Kosaraju’s algorithm for SCC
    bool solve() {
        visited.assign(2 * n, false);
        component.assign(2 * n, -1);

        // Step 1: Fill the order stack
        for (int i = 0; i < 2 * n; i++)
            if (!visited[i])
                dfs1(i);

        // Step 2: Assign components in reverse order
        reverse(order.begin(), order.end());
        int comp = 0;
        for (int v : order)
            if (component[v] == -1)
                dfs2(v, comp++);

        // Step 3: Check for contradiction (x and ¬x in same SCC)
        for (int i = 0; i < n; i++)
            if (component[2 * i] == component[2 * i + 1])
                return false;

        // Step 4: Assign values to variables
        for (int i = 0; i < n; i++) {
            if (component[2 * i] < component[2 * i + 1])
                assignment[i] = 0; // x_i is false
            else
                assignment[i] = 1; // x_i is true
        }

        return true;
    }

    void printAssignment() {
        for (int i = 0; i < n; i++){
            if(assignment[i] == 1){
                cout<<'+'<<" ";
            }
            else{
                cout<<'-'<<" ";
            }
        }
        cout<<endl;
    }
};

/* write core logic here */
void solve(){
    int n,m;
    cin>>m>>n;

    TwoSAT sat(n);

    for(int i = 0; i<m; i++){
        char ch1;
        cin>>ch1;
        int a;
        cin>>a;
        if(ch1 == '-'){
            a = -a;
        }

        char ch2;
        cin>>ch2;
        int b;
        cin>>b;
        if(ch2 == '-'){
            b = -b;
        }
        sat.addClause(a,b);
    }

    if(!sat.solve()){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    sat.printAssignment();
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