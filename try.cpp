/**
 *    author: Saurav
 *    created: 2025.04.22 15:27:34
 *    We stop at Candidate Master in 2025
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
void dfs(int node, int par, vector<vector<int> > &tree, vector<int> &parent){
    parent[node] = par;
    for(auto child : tree[node]){
        if(child == par) continue;
        dfs(child, node, tree, parent);
    }
}

int f(int i, int p, int turn, vector<int> &parent, vector<vector<vector<int> > > &dp, vector<vector<int> > &tree){

    if(i==1) return 0;

    if(dp[i][p][turn] != -1) return dp[i][p][turn];
    
    if(turn == 1){
        return dp[i][p][turn] = f(parent[i] , p, 0, parent, dp, tree) + 1;
    }
    else{
        int ans1 = f(parent[i], p, 1, parent, dp, tree) + 2*tree[i].size() - 1;
        int ans2 = 1e15;

        if(p>0){
            ans2 = f(parent[i], p-1, 1, parent, dp, tree) + 1;
        }

        return dp[i][p][turn] = min(ans1, ans2);
    }
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<vector<int> > tree(n+1);
    for(int i = 0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<vector<vector<int> > > dp(n+1, vector<vector<int> > (n+1, vector<int> (2, -1)));

    vector<int> parent(n+1);

    dfs(1,0, tree, parent);

    print(parent);

    while(q--){
        int i, p;
        cin>>i>>p;
        cout<<f(i, p, 1, parent, dp, tree)<<endl;
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

