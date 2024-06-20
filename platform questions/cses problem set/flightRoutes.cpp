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
#define pp pair<int, int> 
using namespace std;

/* write core logic here */
struct cmp{
    bool operator() (pp &a, pp &b){
        return (a.second) > (b.second);
    }
};

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pp> > graph(n+5, vector<pp> ());
    for(int i = 0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }

    vector<vector<int> > ans(n+5, vector<int> (k, 1e15));
    priority_queue<pp, vector<pp>, cmp > qu;
    qu.push({1,0});
    ans[1][0] = 0;
    while(!qu.empty()){
        pp ff = qu.top();
        qu.pop();
        int u = ff.first;
        int w = ff.second;
        if(ans[u][k-1] < w) continue;
        for(auto neigh : graph[u]){
            if(ans[neigh.first][k-1] > w + neigh.second){
                ans[neigh.first][k-1] = w + neigh.second;
                qu.push({neigh.first , w+neigh.second});
                debug(neigh.first);
                debug(w+neigh.second);
                sort(ans[neigh.first].begin(), ans[neigh.first].end());
            }
        }
    }

    for(int i = 0;i<k; i++){
        cout<<ans[n][i]<<" ";
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

