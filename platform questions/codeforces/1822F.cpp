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
vector<int>  dfs(vector<vector<int> > &tree, int node , vector<int> &visited, vector<vector<int> > &distance){
    // max distance

    visited[node] = 1;
    if(tree[node].size() == 1 and node !=1 ){
         distance[node].push_back(0);
         return {0}; 
    }
    vector<int> v(2, INT_MIN);
    for(auto child : tree[node]){
        if(visited[child] == 0){
            vector<int>  childdist = dfs(tree, child, visited,distance);
            if(childdist[0]+1 > v.back()){
                v.pop_back();
                v.push_back(1 + childdist[0]);
                sort(v.begin(), v.end(), greater<int> ());
            }
        }
    }
    distance[node] = v;
    return v;
}

vector<int>  dfs2 (int node , int parent , vector<vector<int> > &distance){
    vector<int> v(2,  INT_MIN);
    int xx = distance[parent][0];
    if(xx == distance[node][0] + 1){
        xx = distance[parent][1];
    }


    vector<int> vvv;
    vvv.push_back(xx+1);
    vvv.push_back(distance[node][0]);
    vvv.push_back(distance[node][1]);

    sort(vvv.begin(), vvv.end(), greater<int> ());
    v[0] = vvv[0];
    v[1] = vvv[1];
    
    distance[node] = v;

    return v;
}

void dfs3(vector<vector<int>> &tree, int node,int parent,  vector<int> &visited, vector<vector<int> > &distance, vector<int> &xxx){
    visited[node] = 1;
    vector<int> v = dfs2(node, parent, distance);
    debug(node);
    debug(parent);
    print(v);
    int ans = v[0];
    xxx[node] = ans;
    for(auto child : tree[node]){
        if(visited[child] == 0){
            dfs3(tree, child, node, visited, distance, xxx);
        }
    }


    return;
}

void dfs4(vector<vector<int> > &tree, int node, vector<int> &level, int curr, vector<int> &visited){
    level[node] = curr;
    visited[node] = 1;

    for(auto child : tree[node]){
        if(visited[child] == 0){
            dfs4(tree, child, level, curr+1, visited);
        }
    }

    return;
}
void solve(){
    int n,k,c;
    cin>>n>>k>>c;
    vector<vector<int> > tree(n+5, vector<int>());

    for(int i = 0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    print2d(tree);

    vector<int> visited(n+5, 0);
    vector<vector<int> > distance(n+5, vector<int> ());
    vector<int> v = dfs(tree, 1, visited, distance);


    for(int i = 0; i<=n; i++){
        if(distance[i].size() < 2){
            int xx = 2 - distance[i].size();
            for(int j = 0; j<xx; j++){
                distance[i].push_back(INT_MIN);
            }
        }
    }
    print2d(distance);


    int ans = INT_MIN;

    visited.clear();
    visited.resize(n+5, 0);
    vector<int> level(n+5, 0);
    dfs4(tree, 1, level, 0, visited);
    print(level);

    vector<int> xxx(n+5, 0);
    visited.clear();
    visited.resize(n+5, 0);
    dfs3(tree, 1, 0, visited, distance, xxx);

    print(xxx);


    for(int i = 1; i<=n; i++){
        int curr = (xxx[i] * k) - (c * level[i]);
        ans = max(ans, curr);
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

