/**
 *    author: Saurav
 *    created: 2024.10.25 12:52:21
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
class DSU {
private:
    vector<int> parent; // parent[i] = parent of node i
    vector<int> rank;   // rank[i] = approximate depth of subtree rooted at i

public:
    // Constructor to initialize DSU with 'n' elements (0-based indexing)
    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 1); // Initialize all ranks to 1
        for (int i = 1; i <= n; ++i)
            parent[i] = i; // Each element is its own parent initially
    }

    // Find the representative (root) of the set that contains 'x'
    // Implements path compression
    int find_set(int x) {
        if (parent[x] != x)
            parent[x] = find_set(parent[x]); // Path compression
        return parent[x];
    }

    // Union the sets that contain 'x' and 'y'
    // Implements union by rank
    bool union_sets(int x, int y) {
        int x_root = find_set(x);
        int y_root = find_set(y);
        if (x_root == y_root)
            return false; // Already in the same set

        // Union by rank: attach the smaller tree to the root of the larger tree
        if (rank[x_root] < rank[y_root]) {
            parent[x_root] = y_root;
        }
        else if (rank[x_root] > rank[y_root]) {
            parent[y_root] = x_root;
        }
        else {
            parent[y_root] = x_root;
            rank[x_root] += 1; // Only increase rank if both trees have same rank
        }
        return true; // Union was successful
    }

    // Optional: Get the number of disjoint sets
    vector<int>  count_sets() {
        vector<int> connectedcomponents;
        int cnt = 0;
        for (int i = 1; i <= parent.size(); ++i)
            if (parent[i] == i)
                connectedcomponents.push_back(i);
        return connectedcomponents;
    }

    // Optional: Check if two elements are in the same set
    bool same_set(int x, int y) {
        return find_set(x) == find_set(y);
    }
};
void solve(){
    int n;
    cin>>n;

    DSU dsu(n);

    vector<pp> cyclicnodes;

    for(int i = 0; i<n-1; i++){
        int x,y;
        cin>>x>>y;
        int par1 = dsu.find_set(x);
        int par2 = dsu.find_set(y);
        if(par1 == par2){
            cyclicnodes.push_back({x,y});
        }
        else{
            dsu.union_sets(x,y);
        }
    }

    int firstpar = dsu.find_set(1);

    vector<int> connectedcomponents = dsu.count_sets();

    set<int> st;

    for(auto ele : connectedcomponents){
        if(ele == firstpar){
            continue;
        }
        st.insert(ele);
    }

    cout<<cyclicnodes.size()<<endl;

    for(auto ele : cyclicnodes){
        cout<<ele.first<<" "<<ele.second<<" ";
        cout<<firstpar<<" ";
        cout<<*st.begin()<<endl;
        st.erase(st.begin());
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

