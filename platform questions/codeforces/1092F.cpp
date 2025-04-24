/**
 *    author: Saurav
 *    created: 2024.11.05 16:04:13
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

int f(vector<vector<int> > &tree, int node, int par, vector<int> &values, vector<int> &subtreevalues){
    int ans = values[node];
    for(auto child : tree[node]){
        if(child != par){
            ans += f(tree, child, node, values, subtreevalues);
        }
    }
    return subtreevalues[node] = ans;
}

void fdist(vector<vector<int> > &tree, int node, int par, vector<int> &distfrom1, int curr){
    distfrom1[node] = curr;
    for(auto child : tree[node]){
        if(child != par){
            fdist(tree, child, node, distfrom1, curr+1);
        }
    }
}

void parentdfs(vector<vector<int> > &tree , int node, int par, vector<int> &parent){
    parent[node] = par;
    for(auto child : tree[node]){
        if(child != par){
            parentdfs(tree, child, node, parent);
        }
    }
}


int ffinal(int node, int par , int total , vector<int> &subtreevalues, vector<int> &dp, vector<int> &parent){
    if(dp[node] != -1) return dp[node];

    int ans = ffinal(parent[node], parent[parent[node]], total, subtreevalues, dp, parent) - subtreevalues[node] + total - subtreevalues[node];

    return dp[node] = ans;
}

void solve(){
    int n;
    cin>>n;
    vector<int> values(n+1);
    for(int i = 1; i<=n;i++){
        cin>>values[i];
    }

    vector<vector<int> > tree(n+1, vector<int> ());
    for(int i = 0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> subtreevalues(n+1);

    f(tree, 1, 0, values, subtreevalues);

    print(subtreevalues);

    vector<int> distfrom1(n+1);

    distfrom1[0] = -1;

    fdist(tree, 1, 0, distfrom1, 0);

    print(distfrom1);

    vector<int> parent(n+1);

    parentdfs(tree, 1, 0, parent);

    int ans = 0;

    vector<int> dp(n+1, -1);

    for(int i = 2; i<=n; i++){
        ans += values[i] * distfrom1[i];
    }
    dp[1] = ans;

    for(int i = 2; i<=n; i++){
        ans = max(ans , ffinal(i, parent[i], subtreevalues[1], subtreevalues, dp, parent));
        
    }

    cout<<ans;



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

