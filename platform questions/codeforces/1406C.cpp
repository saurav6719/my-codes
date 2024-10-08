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
int dfs1(vector<vector<int>> &tree, int node, vector<int> &visited, vector<int> &size, int parent){
    if(tree[node].size() == 1 and parent != 0 ){
        return size[node] = 1;
    }
    visited[node] = 1;

    int sz = 1;
    for(auto child : tree[node]){
        if(visited[child] == 0){
            sz += dfs1(tree, child, visited, size, node);
        }
    }
    return size[node] = sz;
}

void  dfs2(vector<vector<int>> &tree, int node, vector<int> &visited, vector<int> &size, int &ans, int n){
    visited[node] = 1;
    debug(node);
    bool xx = false;
    for(auto child : tree[node]){
        if(visited[child] == 1)continue;

        // debug(child);
        // debug(size[child]);
        if(size[child] >= (n/2 + n%2) ){
            debug(node);
            xx =true;
            dfs2(tree, child, visited, size, ans, n );
        }
    }

    if(xx == false){
        ans = node;
    }
    return;
}   


void solve(){
    int n;
    cin>>n;
    vector<vector<int> > tree(n+5, vector<int> ());
    vector<pp> edgelist;
    for(int i =0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        edgelist.push_back({u,v});
        edgelist.push_back({v,u});

    }

    vector<int> visited(n+5, 0);
    vector<int> size(n+5);

    dfs1(tree, 1, visited, size, 0);

    print(size);

    int ans;
    visited.clear();
    visited.resize(n+5, 0);
    dfs2(tree, 1, visited, size, ans, n);
    debug(ans);
    // we   found ou t1st centroid
    visited.clear();
    visited.resize(n+5, 0);

    size.clear();
    size.resize(n+5);


    dfs1(tree, ans, visited, size, 0);

    print(size);

    visited.clear();
    visited.resize(n+5, 0);


    int ans2 = -1;
    dfs2(tree, ans, visited, size, ans2, n);
    debug(ans2);

    if(ans2 == -1 or ans2==ans){
        cout<<edgelist[0].first<<" "<<edgelist[0].second<<endl;
        cout<<edgelist[0].first<<" "<<edgelist[0].second<<endl;
        return;
    }

    pp ff = {ans, ans2};
    pp ff2 = {ans2, ans};

    // debug(ans);
    // debug(ans2);

    for(auto ele : edgelist){

        if((ele.first == ans2) and ele.second != ans){
            cout<<ele.first<<" "<<ele.second<<endl;
            cout<<ele.second<<" "<<ans<<endl;
            return;
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

