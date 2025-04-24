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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> >graph(n+5 , vector<int> ());

    while(m--){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    vector<int> indegree(n+5, 0);
    vector<int> visited(n+5, -1);

    queue <int> qu;

    for(int i = 1; i<=n; i++){
        for(auto neigh : graph[i]){
            indegree[neigh]++;
        }
    }

    for(int i = 2; i<=n; i++){
        if(indegree[i] == 0) {
            qu.push(i);
        }
    }

    vector<int> ans;
    vector<int>parent(n+5, -1);

    while(!qu.empty()){
        auto curr = qu.front();
        qu.pop();
        for(auto neigh : graph[curr]){
                indegree[neigh]--;
                if(indegree[neigh] == 0 and neigh != 1){
                    qu.push(neigh);
                    parent[neigh] = curr;
                }
            
        }
    }
    debug(indegree[1]);

    parent[n] = -1;

    qu.push(1);

    while(!qu.empty()){
        auto curr = qu.front();
        debug(curr);
        qu.pop();
        for(auto neigh : graph[curr]){
            debug(neigh);
            debug(indegree[neigh]);
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    //debug(neigh);
                    qu.push(neigh);
                    parent[neigh] = curr;
                }   
        }
    }
    if(parent[n] == -1){
        cout<<"IMPOSSIBLE";
        return;
    }
    int i = n;
    while(i != 1){
        ans.push_back(i);
        i = parent[i];
    }
    ans.push_back(1);

    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(auto ele : ans){
        cout<<ele<<" ";
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

