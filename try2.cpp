/**
 *    author: Saurav
 *    created: 2025.06.28 17:56:19
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

#define printset(s) do { \
    cout << "set-- starts" << endl; \
    for (auto it = s.begin(); it != s.end(); ++it) { \
        cout << *it << endl; \
    } \
    cout << "set-- ends" << endl; \
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
#define printset(s)
#endif
#define endl "\n"
#define MOD 1000000007
#define mod_add(a, b) (((a) % MOD + (b) % MOD) % MOD)
#define mod_sub(a, b) ((((a) % MOD - (b) % MOD) + MOD) % MOD)
#define mod_mul(a, b) (((1LL * (a) % MOD) * (b) % MOD) % MOD)
#define int long long int
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
int cmp(vector<vector<int> > &initial , vector<vector<int> > &final, int n){
    int ans = 0;
    set<pp> initialedges;
    set<pp> finaledges;

    for(int i = 1; i<=n; i++){
        for(int j = 0; j < initial[i].size(); j++){
            if(i < initial[i][j]){
                initialedges.insert({i, initial[i][j]});
            }
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 0; j < final[i].size(); j++){
            if(i < final[i][j]){
                finaledges.insert({i, final[i][j]});
            }
        }
    }

    for(auto ele : initialedges){
        if(finaledges.find(ele) == finaledges.end()){
            ans++;
        }
    }

    for(auto ele : finaledges){
        if(initialedges.find(ele) == initialedges.end()){
            ans++;
        }
    }

    return ans;
}

int ans = 1e5;

void dfs(int node, vector<vector<int> > &currentgraph, int n, vector<vector<int> > &initialgraph){
    if(node == n+1){
        ans = min(ans, cmp(currentgraph, initialgraph, n));
    }

    int currentdegree = currentgraph[node].size();
    if(currentdegree == 0){
        // choose anyone whose current degree <= 1 and dfs to this only

        vector<int> contendors;
        for(int i = 1; i <= n; i++){
            if(currentgraph[i].size() <= 1 and i != node){
                contendors.push_back(i);
            }
        }

        for(auto ele : contendors){
            currentgraph[node].push_back(ele);
            currentgraph[ele].push_back(node);
            dfs(node, currentgraph, n, initialgraph);
            currentgraph[node].pop_back();
            currentgraph[ele].pop_back();
        }
    }
    if(currentdegree == 1){
        // choose anyone whose current degree <= 1 and dfs to that node

        vector<int> contendors;
        for(int i = 1; i <= n; i++){
            if(currentgraph[i].size() <= 1 and i != node and i != currentgraph[node][0]){
                contendors.push_back(i);
            }
        }

        for(auto ele : contendors){
            currentgraph[node].push_back(ele);
            currentgraph[ele].push_back(node);
            dfs(node+1, currentgraph, n, initialgraph);
            currentgraph[node].pop_back();
            currentgraph[ele].pop_back();
        }

    }
    if(currentdegree == 2){
        // just go ahead
        dfs(node+1, currentgraph, n, initialgraph);
    }
    return;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> initialgraph(n+1);
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        initialgraph[u].push_back(v);
        initialgraph[v].push_back(u);
    }

    vector<vector<int>> currentgraph(n+1);

    dfs(1, currentgraph, n, initialgraph);
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

