/* includes and all */

#include<bits/stdc++.h>
#include <cstdlib> 
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

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int a) {
        if (parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
        }
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};

/* write core logic here */

void f(vector<vector<int>> &tree, set<pp> &st, DSU &dsu, int n, int a, int b, int cnt, int cnt2) {
    debug(a);
    debug(b);
    if(cnt2>15*n){
        exit(0);
    }
    if(cnt >= n-1) return;
    if (st.count({a, b}) or st.count({b, a})) return;
    st.insert({a, b});
    st.insert({b, a});
    cout << "? " << a << " " << b << endl;
    cout << flush;
    cnt2++;
    int k1;
    cin >> k1;
    if(k1 == -1) exit(0);

    if (k1 == a || k1 == b) {
        tree[a].push_back(b);
        tree[b].push_back(a);
        dsu.unite(a, b); // unite a and b in DSU
        cnt++;
        return;
    }

    if (!dsu.connected(a, k1)) {
        f(tree, st, dsu, n, a, k1, cnt, cnt2);
    }

    if (!dsu.connected(b, k1)) {
        f(tree, st, dsu, n, b, k1, cnt, cnt2);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    DSU dsu(n);

    set<pp> st;
    for (int i = 2; i <= n; i++) {
        if (st.count({1, n}) || st.count({n, 1})) continue;
        else {
            if (!dsu.connected(1, i)) {
                f(tree, st, dsu, n, 1, i,0, 0);
            }
            st.insert({1, i});
            st.insert({i, 1});
        }   
    }

    cout << "!";
    cout << flush;

    set<pp> ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < tree[i].size(); j++) {
            if (ans.count({i, tree[i][j]}) == 0 && ans.count({tree[i][j], i}) == 0) {
                cout << " " << i << " " << tree[i][j];
                cout << flush;
                ans.insert({i, tree[i][j]});
                ans.insert({tree[i][j], i});
            }
        }
    }


    cout << endl;
    cout << flush;
}

/* logic ends */

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
