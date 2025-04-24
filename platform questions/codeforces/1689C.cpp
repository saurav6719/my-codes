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

int subtreeSize(vector<vector<int> > &tree, vector<int> &visited, int i, vector<int> &res){
    int size = 1;
    visited[i] = 1;
    for(auto child : tree[i]){
        if(visited[child] == 0){
            size += subtreeSize(tree, visited, child, res);
        }
    }
    return res[i] = size;
}

int f(vector<vector<int>>&tree, int i, vector<int> &subtree_size, vector<int> &visited2, vector<int> &ans){
    visited2[i] = 1;
    int maxi = 0;
    vector<int> v;
    for(auto child : tree[i]){
        if(visited2[child] == 0) v.push_back(child);
    }

    if(v.size() == 0){
        return ans[i] = 0;
    }

    if(v.size() == 1){
        return ans[i] = subtree_size[i] - 2;
    }

    int one = v[0];
    int two = v[1];

    // debug(i);
    // debug(one);
    // debug(two);
    int xx = f(tree, two, subtree_size, visited2, ans);
    // debug(xx);
    int yy = f(tree, one, subtree_size, visited2, ans);
    // debug(yy);

    return ans[i]=  max(subtree_size[one] - 1 + xx , subtree_size[two] - 1+yy);

    
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int> > tree(n+5, vector<int> ());

    for(int i =0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // print2d(tree);

    vector<int> subtree_size(n+5);
    vector<int> visited(n+5, 0);
    subtreeSize(tree, visited, 1, subtree_size);
    // print(res);
    vector<int> visited2(n+5, 0);
    vector<int> ans(n+5);
    print(subtree_size);
    cout<<f(tree, 1, subtree_size, visited2, ans)<<endl;
    print(ans);



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

