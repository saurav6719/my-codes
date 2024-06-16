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
#define pp pair<int,int> 
using namespace std;


/* write core logic here */
void dfs3(vector<vector<int> > &graph,vector<int> &visited, vector<int> &paremt, vector<vector<int> > &child, int i , int pare){
    visited[i] = 1;
    paremt[i] = pare;
    child[pare].push_back(i);
    for(auto ele : graph[i]){
        if(visited[ele] == -1){
            dfs3(graph, visited, paremt, child, ele , i);
        }
    }
}

void dfs(vector<vector<int> > &graph,vector<vector<int> > &child, vector<int> &depth, int i, int dep){
    depth[i] = dep;
    for(auto ele : child[i]){
        dfs(graph, child, depth, ele ,dep+1);
    }
}

int dfs2(vector<vector<int> > &graph, vector<int> &visited, vector<int> &size, int i, vector<vector<int> > &child){
    if(child[i].size() == 0){
        return size[i] = 1;
    }
    for(auto ele : child[i]){
        size[i] += dfs2(graph, visited, size,ele,child);
    }
    return size[i] = size[i] + 1;
}



bool cmp(pp a, pp b){
    return a.second > b.second;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int> > graph(n+5, vector<int> ());
    vector<int> visited(n+5, -1);
    vector<int> depth(n+5);
    depth[1] = 1;
    for(int i = 0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> parent(n+5, -1);;
    vector<vector<int> > child(n+5, vector<int> ());
    vector<int> visited3(n+5, -1);
    dfs3(graph,visited, parent, child, 1, 0);


    vector<int> size(n+5, 0);
    dfs(graph, child, depth, 1, 1);
    print(depth);

    
    int a = dfs2(graph, visited, size, 1, child);
    size[1] = a;
    print(size);

    vector<int> ans;
    for(int i = 1; i<=n; i++){
        int ind = size[i] * (depth[i]-1);
        int tou = (size[i]-1) * depth[i];
        ans.push_back(tou - ind);
    }

    print(ans);

    sort(ans.begin(), ans.end(), greater<int> ());

    int cnt = 0;

    for(int i = 0; i<n-k; i++){
        cnt+= ans[i];
    }

    cout<<cnt<<endl;
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

