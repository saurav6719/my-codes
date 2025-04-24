/**
 *    author: Saurav
 *    created: 2024.10.23 15:46:39
 **/

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

void dfs(vector<vector<int> > &tree, int node, int par, vector<int> &parent){
    parent[node] = par;

    for(auto child : tree[node]){
        if(child == par) continue;
        dfs(tree, child, node, parent);
    }
    return;
}
void solve(){
    int n,k;
    cin>>n>>k;
    int x,y;
    cin>>x>>y;
    vector<int> extra(k);
    for(int i = 0; i<k; i++){
        cin>>extra[i];
    }

    vector<vector<int> > tree(n+1, vector<int> ());

    for(int i = 0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> parent(n+1, 0);

    dfs(tree, x, 0, parent);

    print(parent);

    set<int> visited;

    int start = y;
    int ans = 0;

    while(start != x){
        ans ++;
        visited.insert(start);
        start = parent[start];
    }
    visited.insert(x);

    // for(auto ele : visited){
    //     cout<<ele<<" ";
    // }
    // cout<<endl;

    for(auto ele : extra){
        if(visited.count(ele)) continue;
        int start2 = ele;
        while(true){
            if(visited.count(start2)) break;
            ans += 2;
            visited.insert(start2);
            start2 = parent[start2];
        }
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

