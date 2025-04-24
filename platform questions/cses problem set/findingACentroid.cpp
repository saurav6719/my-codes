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
int dfs(int node, vector<vector<int> > &tree, vector<int> &subtreeSize, vector<int> &visited){
    visited[node] = 1;
    int curr = 0;
    for(auto child : tree[node]){
        if(visited[child] == -1){
            curr += dfs(child , tree, subtreeSize, visited);
        }
    }
    return subtreeSize[node] = 1+curr;
}

int ans(vector<int> &subtreeSize, int node, int n, vector<vector<int> > &tree, vector<int> &visited2){
    visited2[node] = 1;
    for(auto child : tree[node]){
        if(visited2[child] == 1) continue;
        if(subtreeSize[child] > n/2){
            return ans(subtreeSize, child, n, tree, visited2);
        }
    }

    return node;
}


void solve(){
    int n;
    cin>>n;
    vector<vector<int> > tree(n+5, vector<int> ());
    for(int i = 0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<int> subtreeSize(n+5, 0);
    vector<int> visited(n+5, -1);

    dfs(1, tree,subtreeSize, visited);
    print(subtreeSize);

    vector<int> visited2(n+5, -1);

    int res = ans(subtreeSize, 1, n, tree, visited2);
    cout<<res;


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

