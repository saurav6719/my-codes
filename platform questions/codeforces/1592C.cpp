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
int xori(vector<vector<int> > &tree, int node, vector<int> &xorr,  vector<int> &visited, vector<int> &parent, vector<int> &values){
    if(tree[node].size() == 1 and node != 1){        
        return xorr[node] = values[node];
    }

    visited[node] = 1;
    int currxor = values[node];
    for(auto child : tree[node]){
        if(visited[child] == 0){
            parent[child] = node;
            currxor ^= xori(tree, child, xorr, visited, parent, values);
        }
    }

    return xorr[node] = currxor;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> values(n+1);
    for(int i = 1; i<=n; i++){
        cin>>values[i];
    }
    vector<vector<int> > tree(n+5, vector<int>());
    for(int i = 0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> xorr(n+5);
    vector<int> visited(n+5, 0);
    vector<int> parent(n+5);
    parent[1] = 0;

    int xx = xori(tree, 1, xorr, visited, parent, values);

    print(xorr);
    int ele = -1;
    int overall = xorr[1];

    if(overall == 0){
        cout<<"YES"<<endl;
        return;
    }

    map<int,int> mp;
    for(int i = 2; i<=n; i++){
        mp[xorr[i]]++;
    }

    if(mp[overall] >= 3 and k>2){
        cout<<"YES"<<endl;
        return;
    }


    for(int i = 2; i<=n; i++){
        if(xorr[i] == overall){
            ele = i;
            break;
        }
    }

    if(ele == -1){
        cout<<"NO"<<endl;
        return;
    }

    int par = parent[ele];

    vector<vector<int> > newtree= tree;

    vector<int> v;
    for(auto j : tree[ele]){
        if(j!= par){
            v.push_back(j);
        }
    }

    debug(ele);
    debug(par);

    newtree[ele] = v;

    vector<int> v2;
    for(auto j : tree[par]){
        if(j!= ele){
            v2.push_back(j);
        }
    }

    newtree[par] = v2;

    print2d(newtree);
    xorr.clear();
    xorr.resize(n+5, -1);
    visited.clear();
    visited.resize(n+5, 0);
    parent.clear();
    parent.resize(n+5);
    parent[1] = 0;

    int xxy = xori(newtree, 1, xorr, visited, parent, values);
    print(xorr);

    for(int i = 1; i<=n; i++){
        if(xorr[i] == overall and k>2){
            cout<<"YES"<<endl;
            return;
        }
    }

    cout<<"NO"<<endl;
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

