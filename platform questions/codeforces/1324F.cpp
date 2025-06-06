/**
 *    author: Saurav
 *    created: 2024.10.17 15:31:02
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
vector<int> dp;
vector<int> reroutedp;

int dfs(vector<vector<int> > &tree, int node, int par, vector<int> &colour){
    int ans = 0;
    if(colour[node] == 1){
        ans = 1;
    }
    else ans = -1;
    for(auto child : tree[node]){
        if(child != par){
            ans += max(0ll,dfs(tree,child,node,colour));
        }
    }
    return dp[node] = ans;
}

void rerouting(vector<vector<int> > &tree, vector<int> &dp, int node, int par, vector<int> &colours){
    int ans = reroutedp[par];

    if(dp[node] > 0){
        ans -= dp[node];
    }

    ans = max(dp[node] + ans , dp[node]);

    if(ans <-1) ans  = -1;

    reroutedp[node] = ans;


    for(auto child : tree[node]){
        if(child != par){       
            rerouting(tree,dp,child,node, colours);
        }
    }
}


void solve(){
    int n ;

    cin>>n;
    vector<int> colours(n+1);
    for(int i=1;i<=n;i++){
        cin>>colours[i];
    }

    vector<vector<int> > tree(n+1, vector<int> ());

    for(int i=1;i<n;i++){
        int u , v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dp.resize(n+1,0);
    reroutedp.resize(n+1,0);

    int xx = dfs(tree,1,0,colours);

    print(dp);
    reroutedp[0] = dp[1];

    rerouting(tree,dp,1,0, colours);
    print(reroutedp);

    for(int i = 1; i<=n; i++){
        cout<<reroutedp[i]<<" ";
    }
    cout<<endl;
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

