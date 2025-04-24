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
bool dfs(map<string , set<string> > &graph, int i1,int j1, int i2, int j2, int ans , vector<vector<int> > &visited, string direction, int n, int m){
    string newstr = to_string(i1) + '+' + to_string(j1);
    if(visited[i1][j1] == 1 and graph[newstr].count(direction)){
        cout<<-1<<endl;
        return false;
    }
    visited[i1][j1] = 1;
    graph[newstr].insert(direction);
    if(i1==i2 and j1==j2){
        cout<<ans<<endl;
        return true;
    }
    // hit corner 
    if(i1==0 and j1==0 and direction == "UL") {
        return dfs(graph, 0,0, i2, j2, ans+1, visited, "DR", n ,m );
        
    }
    if(i1==0 and j1 == m-1 and direction == "UR"){
        return dfs(graph, 0, m-1, i2, j2, ans+1, visited, "DL", n,m);
    }
    if(i1==n-1 and j1==0 and direction == "DL"){
        return dfs(graph, n-1, 0, i2, j2, ans+1, visited, "UR", n,m);
    }
    if(i1==n-1 and j1==m-1 and direction == "DR"){
        return dfs(graph, n-1, m-1, i2, j2, ans+1, visited, "UL", n,m);
    }
    //hit walls 
    if(i1==0){
        if(direction == "UL"){
            return dfs(graph, i1, j1, i2, j2, ans+1, visited, "DL", n,m);
        }
        if(direction == "UR"){
            return dfs(graph, i1, j1, i2, j2, ans+1, visited, "DR", n,m);
        }
    }

    if(i1==n-1){
        if(direction == "DL"){
            return dfs(graph, i1, j1, i2, j2, ans+1, visited, "UL", n,m);
        }
        if(direction == "DR"){
            return dfs(graph, i1, j1, i2, j2, ans+1, visited, "UR", n,m);
        }
    }
    if(j1==0){
        if(direction == "UL"){
            return dfs(graph, i1, j1, i2, j2, ans+1, visited, "UR", n,m);
        }
        if(direction == "DL"){
            return dfs(graph, i1, j1, i2, j2, ans+1, visited, "DR", n,m);
        }
    }
    if(j1==m-1){
        if(direction == "UR"){
            return dfs(graph, i1, j1, i2, j2, ans+1, visited, "UL", n,m);
        }
        if(direction == "DR"){
            return dfs(graph, i1, j1, i2, j2, ans+1, visited, "DL", n,m);
        }
    }
    //not walls not corner

    if(direction == "UL"){
        return dfs(graph, i1-1, j1-1, i2, j2, ans, visited, direction , n, m);
    }
    if(direction == "UR"){
        return dfs(graph, i1-1, j1+1, i2, j2, ans, visited, direction , n, m);
    }

    if(direction == "DL"){
        return dfs(graph, i1+1, j1-1, i2, j2, ans, visited, direction , n, m);
    }

    if(direction == "DR"){
        return dfs(graph, i1+1, j1+1, i2, j2, ans, visited, direction , n, m);
    }
    return true;
}
void solve(){
    int n,m;
    cin>>n>>m;
    int i1,j1;
    cin>>i1>>j1;
    int i2,j2;
    cin>>i2>>j2;
    string d;
    cin>>d;
    i1--;
    j1--;
    i2--;
    j2--;

    map<string, set<string> > graph;
    vector<vector<int> > visited(n, vector<int> (m, 0));

    dfs(graph, i1, j1, i2, j2, 0, visited, d, n, m);
    return;


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

