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
vector<int> dp;
int dfs(int node, vector<vector<int> > &graph, vector<int> &visited,set<int> &cycle, set<int> &newcycle){
    visited[node] = 1;
    cycle.insert(node);
    for(auto child: graph[node]){
        if(!visited[child]){
            int xx = dfs(child, graph, visited, cycle, newcycle);
            if(newcycle.count(node) == 0){
                return dp[node] = -1;
            }
            return dp[node] = xx;
        }
    }

    int startcyle = node;
    int endcycle = graph[node][0];

    if(cycle.count(endcycle) == 0) return -1;


    vector<int> v;
    
    while(startcyle != endcycle){
        v.push_back(endcycle);
        newcycle.insert(endcycle);
        endcycle = graph[endcycle][0];
    }

    v.push_back(startcyle);
    newcycle.insert(startcyle);

 
    return dp[node] = v.size();
}
 
int f(int x, vector<int> &dp, vector<vector<int> > &graph){
    if(dp[x] != -1) return dp[x];
 
    return dp[x] = 1 + f(graph[x][0], dp, graph);
}
void solve(){
    int n;
    cin>>n;
 
    dp.resize(n+1, -1);
 
 
 
    vector<int> input(n+1);
    vector<vector<int> > graph(n+5, vector<int>());
 
    for(int i=1; i<=n; i++){
        cin>>input[i];
        graph[i].push_back(input[i]);
    }
 
    vector<int> visited(n+1, 0);
 
    for(int i = 1; i<=n; i++){
        if(dp[i] == -1){
            set<int> cycle;
            set<int> newcycle;
            int yy = dfs(i, graph, visited, cycle, newcycle);
        }
    }
 
 
 
    print(dp);
 
    for(int i=1; i<=n; i++){
        if(dp[i] == -1){
            int yy = f(i, dp, graph);
        }
    }
 
    for(int i=1; i<=n; i++){
        cout<<dp[i]<<" ";
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
