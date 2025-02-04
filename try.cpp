/**
 *    author: Saurav
 *    created: 2025.02.04 16:53:41
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

/* write core logic here */
const int MAX_N = 100005;  // Maximum number of nodes
const int LOG = 20;        // log2(MAX_N) ~ 17, so we take slightly more

vector<int> adj[MAX_N];    // Adjacency list
int up[MAX_N][LOG];        // up[v][j] stores the 2^j-th ancestor of v
int depth[MAX_N];          // Depth of each node

// Preprocessing: Build the binary lifting table
void dfs(int node, int parent) {
    up[node][0] = parent; // Direct parent

    // Fill 2^j ancestors for this node
    for (int j = 1; j < LOG; j++) {
        if (up[node][j-1] != -1)
            up[node][j] = up[up[node][j-1]][j-1];
        else
            up[node][j] = -1;
    }

    for (int child : adj[node]) {
        if (child != parent) {
            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
    }
}

// Find K-th ancestor of a node
int getKthAncestor(int node, int k) {
    for (int j = 0; j < LOG; j++) {
        if (k & (1 << j)) { // Check if this bit is set
            node = up[node][j];
            if (node == -1) return -1; // If ancestor doesn't exist
        }
    }
    return node;
}

// Find LCA of two nodes
int getLCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v); // Ensure u is deeper

    // Bring u and v to the same depth
    int diff = depth[u] - depth[v];
    u = getKthAncestor(u, diff);

    if (u == v) return u; // If v is the ancestor of u

    // Lift both nodes upwards until their parents match
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0]; // The LCA is the parent of u (or v)
}
vector<int> subtree;

int subtreesize(int node, int par){
    int size = 1;
    for(int child : adj[node]){
        if(child != par){
            size += subtreesize(child, node);
        }
    }
    subtree[node] = size;
    return size;
}
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    subtree.assign(n+1,0);
    subtreesize(1,-1);

    // Initialize the binary lifting table

    memset(up, -1, sizeof up);

    // Assume 1 as the root and build the binary lifting table

    depth[1] = 0;
    dfs(1, -1);

    int q;
    cin>>q;

    while(q--){
        int a,b;
        cin>>a>>b;

        if(a==b){
            cout<<n<<endl;
            continue;
        }
        int lca = getLCA(a,b);

        if(lca == a or lca == b){
            if(lca == b) swap(a,b);
            int depthofa = depth[a];
            int depthofb = depth[b];
            int differenceindepth = depthofb - depthofa;

            if(differenceindepth % 2 == 0){
                int z = getKthAncestor(b, differenceindepth/2);
                int currans = subtree[z];
                z = getKthAncestor(b, differenceindepth/2 - 1);
                currans -= subtree[z];
                cout<<currans<<endl;
            }
            else cout<< 0<<endl;
        }
        else{
            int x = depth[a] - depth[lca];
            int y = depth[b] - depth[lca];

            if(x != y){
                int distancebetween = depth[a] + depth[b] - 2*depth[lca];

                if(distancebetween % 2 == 1){
                    cout<<0<<endl;
                    continue;
                }

                if(depth[b] < depth[a]) swap(a,b);

                int mid = getKthAncestor(b, distancebetween/2);

                int currans = subtree[mid];
                int justbelow = getKthAncestor(b, distancebetween/2 - 1);

                currans -= subtree[justbelow];

                justbelow = getKthAncestor(a, distancebetween/2 - 1);

                int sizee = subtree[justbelow];
                if(sizee < subtree[mid]){
                    currans -= sizee;
                }

                cout<<currans<<endl;
            }
            else{
                int ans = n;
                int z = getKthAncestor(a, x-1);
                ans -= subtree[z];
                z = getKthAncestor(b, y-1);
                ans -= subtree[z];

                cout<<ans<<endl;
            }
        }
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

