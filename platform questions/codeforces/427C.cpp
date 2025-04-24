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

void dfs1(vector<vector<int> > &graph, vector<int> &dfsorder, int node, vector<int> &visited){
    visited[node] = 1;
    for(auto neigh : graph[node]){
        if(visited[neigh] == 0){
            dfs1(graph, dfsorder, neigh, visited);
        }
    }

    dfsorder.push_back(node);
}

void dfs2(vector<vector<int> > &graph, vector<int> &visited, int node, vector<int> &v){
    visited[node] = 1;
    v.push_back(node);
    for(auto neigh : graph[node]){
        if(visited[neigh] == 0){
            dfs2(graph, visited,neigh, v);
        }
    }
    return;
}

const int MOD = 1e9 + 7;

// Function to calculate power in modular arithmetic
long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1; // y = y/2
        x = (x * x) % MOD;
    }
    return res;
}

// Function to calculate factorial in modular arithmetic
long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; ++i)
        res = (res * i) % MOD;
    return res;
}

// Function to calculate nCr in modular arithmetic
long long nCr(int n, int r) {
    if (r == 0 || r == n)
        return 1;
    long long numerator = factorial(n);
    long long denominator = (factorial(r) * factorial(n - r)) % MOD;
    return (numerator * power(denominator, MOD - 2)) % MOD;
}

void solve(){
    int n;
    cin>>n;
    vector<int> cost(n+1);
    for(int i = 1; i<=n; i++){
        cin>>cost[i];
    }

    int m;
    cin>>m;
    vector<vector<int> > graph(n+5, vector<int> ());
    vector<vector<int> > reversegraph(n+5, vector<int> ());


    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        reversegraph[v].push_back(u);
    }

    vector<int> visited(n+5, 0);
    vector<int> dfsorder;
    // dfs1(graph, dfsorder, 1, visited);

    for(int i= 1; i<=n; i++){
        if(visited[i] == 0){
            dfs1(graph, dfsorder, i, visited);
        }
    }

    // int next_node = dfsorder.back();
    reverse(dfsorder.begin(), dfsorder.end());
    print(dfsorder);

    visited.clear();
    visited.resize(n+5, 0);

    vector<vector<int> > ssc;
    // debug(next_node);


    print2d(reversegraph);

    for(int i = 0; i<dfsorder.size(); i++){
        if(visited[dfsorder[i]] == 0){
            vector<int> v;
            dfs2(reversegraph, visited, dfsorder[i], v);
            ssc.push_back(v);
            print(v);
        }
    }

    print2d(ssc);

    int ans = 0;
    // int ways = 1;
    vector<int> ways;

    for(int i = 0; i<ssc.size(); i++){
        vector<int> &v = ssc[i];
        map<int,int> mp;
        for(auto ele : v){
            mp[cost[ele]]++;
        }

        int mini = INT_MAX;
        for(auto ele : mp){
            if(ele.first < mini){
                mini = ele.first;
            }
        }

        ways.push_back(mp[mini]);
        ans += mini; 
    }

    cout<<ans<<" ";

    int no_of_ways = 1;
    for(auto ele : ways){
        no_of_ways *= ele;
        no_of_ways %= mod;
    }

    cout<<no_of_ways<<endl;








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

