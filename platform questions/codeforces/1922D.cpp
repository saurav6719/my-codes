/**
 *    author: Saurav
 *    created: 2024.12.12 02:22:15
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

void dfs(int node, int par, vector<vector<int>> &tree, vector<int> &subtreesize, vector<int> &subtreeimportance, vector<int> &importance){
    subtreesize[node] = 1;
    subtreeimportance[node] = importance[node];
    for(auto x : tree[node]){
        if(x != par){
            dfs(x, node, tree, subtreesize, subtreeimportance, importance);
            subtreesize[node] += subtreesize[x];
            subtreeimportance[node] += subtreeimportance[x];
        }
    }
}

struct NodeInfo {
    int index;
    int subtreesize;

    // For debugging or printing
    friend std::ostream& operator<<(std::ostream& os, const NodeInfo& n) {
        os << "{index: " << n.index << ", subtreesize: " << n.subtreesize << "}";
        return os;
    }
};

struct CustomComparator {
    bool operator()(const NodeInfo& a, const NodeInfo& b) const {
        if (a.subtreesize == b.subtreesize) {
            return a.index < b.index; // Smaller index comes first if sizes are equal
        }
        return a.subtreesize > b.subtreesize; // Larger subtreesize comes first
    }
};


void dfs2(vector<vector<int> > &tree , vector<int> &subtreesize, vector<int> &parent, map<int, set<NodeInfo, CustomComparator>> &childrensinfo, int node, int par){
    parent[node] = par;

    for(auto child : tree[node]){
        if(child == par) continue;
        childrensinfo[node].insert({child, subtreesize[child]});
        dfs2(tree, subtreesize, parent, childrensinfo, child, node);
    }

}


void solve(){
    int n,q;
    cin>>n>>q;

    vector<int> importance(n+1);
    for(int i =1; i<=n; i++){
        cin>>importance[i];
    }

    vector<vector<int> > tree(n+1, vector<int> ());
    for(int i = 0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> subtreesize(n+1, 0);
    vector<int> subtreeimportance(n+1, 0);

    dfs(1, 0, tree, subtreesize, subtreeimportance, importance);

    print(subtreesize);
    print(subtreeimportance);

    map<int, set<NodeInfo, CustomComparator>> childrensinfo;

    vector<int> parent(n+1, 0);

    dfs2(tree, subtreesize, parent, childrensinfo, 1, 0);

    while(q--){
        int type;
        cin>>type;

        if(type == 1){
            int x;
            cin>>x;
            cout<<subtreeimportance[x]<<endl;
        }
        else{
            int x;
            cin>>x;

            if(childrensinfo[x].empty()){
                continue;
            }

            int currnode = x;
            int currparent = parent[x];
            int currheaviestchild = childrensinfo[x].begin()->index;

            // remove edge from parent to node x

            childrensinfo[currparent].erase({currnode, subtreesize[currnode]});
            childrensinfo[currnode].erase({currheaviestchild, subtreesize[currheaviestchild]});
            subtreesize[currnode] -= subtreesize[currheaviestchild];
            subtreesize[currheaviestchild] += subtreesize[currnode];

            subtreeimportance[currnode] -= subtreeimportance[currheaviestchild];
            subtreeimportance[currheaviestchild] += subtreeimportance[currnode];

            // add edge from parent to heaviest child 

            childrensinfo[currparent].insert({currheaviestchild, subtreesize[currheaviestchild]});
            childrensinfo[currheaviestchild].insert({currnode, subtreesize[currnode]});

            parent[currnode] = currheaviestchild;
            parent[currheaviestchild] = currparent;
        }
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

