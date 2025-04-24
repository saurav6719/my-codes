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
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
vector<int> color;

void bfs(vector<vector<int>>& graph, int src) {
    queue<int> q;
    q.push(src);
    color[src] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (color[v] == -1) { // if uncolored
                color[v] = 1 - color[u]; // alternate color
                q.push(v);
            }
        }
    }
}


void solve() {
    int n;
    cin >> n;
    set<int> st1;
    set<int> st2;
    map<int, int> mp;
    int m = n - 1;
    vector<vector<int>> graph(n + 1); // Adjust size to n + 1

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // assuming undirected graph
        mp[u]++;
        mp[v]++;
    }

    color.assign(n + 1, -1); // Initialize all nodes as uncolored

    // Perform BFS from each uncolored node
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) { // If node is uncolored
            bfs(graph, i); // Color connected component starting from node i
        }
    }

    vector<int> set1, set2;

    for (int i = 1; i <= n; i++) { // Adjust loop to start from 1
        if (color[i] == 0) set1.push_back(i);
        else set2.push_back(i);
    }
    for(auto ele : set1){
        st1.insert(ele);
    }

    for(auto ele : set2){
        st2.insert(ele);
    }

    int ans = 0;

    for (auto ele : st1) {
        int cnt1 = mp[ele];
        ans += (st2.size() - cnt1);
    }
    cout << ans;
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

