/**
 *    author: Saurav
 *    created: 2024.12.07 03:03:14
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

class MergeSortTree {
private:
    std::vector<std::vector<int>> tree;
    int n;

    void build(int node, int start, int end, const std::vector<int>& arr) {
        if (start == end) {
            tree[node] = {arr[start]};
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid, arr);
            build(2 * node + 1, mid + 1, end, arr);
            
            // Merge the two child nodes
            std::merge(tree[2 * node].begin(), tree[2 * node].end(),
                       tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
                       std::back_inserter(tree[node]));
        }
    }

    int query(int node, int start, int end, int l, int r, int k) {
        if (start > r || end < l) {
            return 0; // Out of range
        }
        if (start >= l && end <= r) {
            // Complete overlap
            return std::upper_bound(tree[node].begin(), tree[node].end(), k) -
                   std::lower_bound(tree[node].begin(), tree[node].end(), k);
        }

        int mid = (start + end) / 2;
        int leftQuery = query(2 * node, start, mid, l, r, k);
        int rightQuery = query(2 * node + 1, mid + 1, end, l, r, k);
        return leftQuery + rightQuery;
    }

public:
    MergeSortTree(const std::vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, arr);
    }

    int query(int l, int r, int k) {
        return query(1, 0, n - 1, l, r, k);
    }
};




/* write core logic here */
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &x : v){
        cin>>x;
    }

    int ans = 0;

    vector<int> v2 = v;
    reverse(v2.begin(), v2.end());

    for(int j = 0; j<n; j++){
        unordered_map<int,int> mp1;
        for(int i = 0; i<j; i++){
            mp1[v[i]] ++;
        }
        unordered_map<int,int> mp2;
        for(int i = 0; i<n-j-1; i++){
            mp2[v2[i]] ++;
        }
        for(int k = j+1; k<n; k++){
            int valatk = v[k];
            int valatj = v[j];
            mp2[valatk] --;
            ans += mp1[valatk] * mp2[valatj];
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

