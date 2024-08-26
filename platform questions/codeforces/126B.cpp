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
vector<vector<int> > comp;

void dfs(vector<vector<int> > &graph, int node, vector<int> &visited, vector<int> &v){
    visited[node] = 1;
    v.push_back(node);
    for(auto child : graph[node]){
        if(visited[child] == 0){
            dfs(graph , child, visited, v);
        }
    }
}

int find(vector<int> &par, int x) {
    if (par[x] == x) return x;
    return par[x] = find(par, par[x]);  // Path compression
}

void Union(vector<int> &rank, vector<int> &par, vector<int> &minVal, vector<int> &maxVal, int a, int b) {
    a = find(par, a);
    b = find(par, b);
    
    if (a == b) return;  // Already in the same set
    
    if (rank[a] < rank[b]) {
        par[a] = b;
        minVal[b] = min(minVal[a], minVal[b]);
        maxVal[b] = max(maxVal[a], maxVal[b]);
    } else if (rank[a] > rank[b]) {
        par[b] = a;
        minVal[a] = min(minVal[a], minVal[b]);
        maxVal[a] = max(maxVal[a], maxVal[b]);
    } else {
        par[b] = a;
        rank[a]++;
        minVal[a] = min(minVal[a], minVal[b]);
        maxVal[a] = max(maxVal[a], maxVal[b]);
    }
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);  // Graph initialization

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> par(n + 1), rank(n + 1, 0), minVal(n + 1), maxVal(n + 1);

    // Initialize parent, min, and max values
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        minVal[i] = i;
        maxVal[i] = i;
    }

    vector<int> visited(n + 1, 0);
    vector<vector<int>> comp;

    // Finding components via DFS
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> v;
            dfs(graph, i, visited, v);
            sort(v.begin(), v.end());
            comp.push_back(v);
        }
    }

    vector<pair<int, int>> intervals;
    
    for(const auto & v: comp){
        intervals.push_back({v[0], v.back()});
    }

    sort(intervals.begin(), intervals.end());

    int ans = 0;
    int maxEnd = intervals[0].second;

    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i].first <= maxEnd) {
            ans++;
        }
        maxEnd = max(maxEnd, intervals[i].second);
    }

    cout << ans << endl;

    // cout << ans << endl;
}

/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

