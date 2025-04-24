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

bool cmp(int lhs, int rhs) {
    return lhs > rhs;
}

void solve(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int> > graph(n+1, vector<int> ());

    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    priority_queue<int, vector<int> ,greater<int> > pq;

    pq.push(1);

    vector<int> ans;
    vector<int> visited(n+5, -1);

    

    while(!pq.empty()){
        int ff = pq.top();
        ans.push_back(ff);
        visited[ff] = 1;

        pq.pop();
        for(auto ele :graph[ff]){
            if(visited[ele] == -1){
                pq.push(ele);
                visited[ele] = 1;
            }
        }

    }

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

