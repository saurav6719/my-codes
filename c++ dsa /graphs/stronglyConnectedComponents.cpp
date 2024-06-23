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
void dfs(int node , vector<int> &visited1 , vector<vector<int> > &graph, vector<int> &dfssort){
    visited1[node] = 1;
    for(auto neigh : graph[node]){
        if(visited1[neigh] == -1){
            dfs(neigh , visited1 , graph, dfssort);
        }
    }

    dfssort.push_back(node);
}
void solve(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int> > graph(n+5, vector<int> ());

    while(m--){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    vector<int> visited1(n+5, -1);
    vector<int> dfssort;
    dfs(0, visited1, graph, dfssort);
    reverse(dfssort.begin(), dfssort.end());
    vector<vector<int> > reversegraph(n+5, vector<int> ());
    for(int i = 0; i<n; i++){
        for(int j = 0; j<graph[i].size(); j++){
            reversegraph[graph[i][j]].push_back(i);
        }
    }
    vector<int> v;
    vector<vector<int> >final;
    int number = 0;
    vector<int> visited2(n+5, -1);
    for(int i = 0; i<dfssort.size(); i++){
        if((visited2[dfssort[i]]) == -1){
            number++;
            dfs(dfssort[i] , visited2, reversegraph , v);
            final.push_back(v);
            v.clear();
        }
    }

    cout<<number<<endl;
    for(int i= 0; i<final.size(); i++){
        for(int j = 0;j<final[i].size(); j++){
            cout<<final[i][j]<<" ";
        }

        cout<<endl;
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

