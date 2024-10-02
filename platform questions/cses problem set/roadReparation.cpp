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

int find(vector<int> &parent, int x){
    return parent[x] == x ? x : find(parent, parent[x]);
}

void Union(vector<int> &parent,vector<int> &rank, int a, int b){
    a = find(parent,a);
    b = find(parent,b);
    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }
    else{
        rank[b]++;
        parent[a] = b;
    }
}

struct edges{
    int u,v,w;
};

void solve(){
    int n,m;
    cin>>n>>m;

    vector<edges> edge(m);

    for(int i=0; i<m; i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }

    sort(edge.begin(), edge.end(), [&](edges a, edges b){
        return a.w < b.w;
    });

    int ans = 0;

    vector<int> parent(n+1);

    vector<int> rank(n+1,0);

    for(int i = 0; i<=n ; i++){
        parent[i] = i;
    }

    for(int i = 0; i<m; i++){
        if(find(parent, edge[i].u) != find(parent, edge[i].v)){
            Union(parent, rank, edge[i].u, edge[i].v);
            ans += edge[i].w;
        }
    }

    int noofconnectedcomponnets = 0;

    for(int i=1; i<=n; i++){
        if(parent[i] == i) noofconnectedcomponnets++;
    }

    if(noofconnectedcomponnets > 1) cout<<"IMPOSSIBLE"<<endl;
    else 

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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

