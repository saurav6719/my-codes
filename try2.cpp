/**
 *    author: Saurav
 *    created: 2025.05.01 05:23:43
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
#endif
#define endl "\n"
#define MOD 1000000007
#define mod_add(a, b) (((a) % MOD + (b) % MOD) % MOD)
#define mod_sub(a, b) ((((a) % MOD - (b) % MOD) + MOD) % MOD)
#define mod_mul(a, b) (((1LL * (a) % MOD) * (b) % MOD) % MOD)
// #define int long long int
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */

class SegmentTree {
private:
    int n;
    vector<vector<int>> tree;
    vector<vector<int>> left;
    vector<vector<int>> right;
    vector<int> data;

    // Function to build the segment tree
    void build(int node, int start, int end) {
        if (start == end) {
            // Leaf node will have a single element
            tree[node].push_back(data[start]);
            return;
        }

        int mid = start + (end - start) / 2;
        int left_child = 2 * node + 1;
        int right_child = 2 * node + 2;

        // Recursively build the left and right children
        build(left_child, start, mid);
        build(right_child, mid + 1, end);

        // Merge the sorted vectors from left and right children
        mergeVectors(tree[left_child], tree[right_child], tree[node]);
        cascade(tree[left_child], tree[node], left[node]);
        cascade(tree[right_child], tree[node], right[node]);
    }

    // Helper function to merge two sorted vectors
    void mergeVectors(const vector<int> &left, const vector<int> &right, vector<int> &merged) {
        merged.resize(left.size() + right.size());
        merge(left.begin(), left.end(), right.begin(), right.end(), merged.begin());
    }

    void cascade(const vector<int>& prev, const vector<int>& now, vector<int>& ptr) {
        ptr.resize(now.size());
        int i = 0;
        for (int j = 0; j < (int)now.size(); ++j) {
            while (i < (int)prev.size() && prev[i] < now[j]) ++i;
            ptr[j] = i;
        }
    }

    // Function to perform the query
    int queryUtil(int node, int start, int end, int L, int R, int X, int idx) const {
        if (R < start || end < L) {
            // No overlap
            return 0;
        }

        if (L <= start && end <= R) {
            // Total overlap
            return idx;
        }

        // Partial overlap
        int mid = start + (end - start) / 2;
        int left_child = 2 * node + 1;
        int right_child = 2 * node + 2;

        int left_idx, right_idx;
        if(idx == tree[node].size()){
            left_idx = tree[left_child].size();
            right_idx = tree[right_child].size();
        }
        else{
            left_idx = left[node][idx];
            right_idx = right[node][idx];
        }

        int count_left = queryUtil(left_child, start, mid, L, R, X, left_idx);
        int count_right = queryUtil(right_child, mid + 1, end, L, R, X, right_idx);

        return count_left + count_right;
    }

public:
    // Constructor to initialize and build the segment tree
    SegmentTree(const vector<int> &input_data) {
        data = input_data;
        n = data.size();
        // Allocate enough space for the segment tree
        tree.resize(4 * n);
        left.resize(4 * n);
        right.resize(4 * n);
        build(0, 0, n - 1);
    }

    // Function to query the frequency of X in range [L, R]
    int query(int L, int R, int X) const {
        if (L < 0 || R >= n || L > R) {
            throw invalid_argument("Invalid query range.");
        }
        int idx = upper_bound(tree[0].begin(), tree[0].end(), X) - tree[0].begin();
        return queryUtil(0, 0, n - 1, L, R, X, idx);
    }


    void print_tree() {
        // cout << "Segment Tree:" << endl;
        // for (int i = 0; i < tree.size(); i++) {
        //     cout << "Node " << i << ": ";
        //     for (int j = 0; j < tree[i].size(); j++) {
        //         cout << tree[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << "Left:" << endl;
        for (int i = 0; i < left.size(); i++) {
            cout << "Node " << i << ": ";
            for (int j = 0; j < left[i].size(); j++) {
                cout << left[i][j] << " ";
            }
            cout << endl;
        }
        // cout << "Right:" << endl;
        // for (int i = 0; i < right.size(); i++) {
        //     cout << "Node " << i << ": ";
        //     for (int j = 0; j < right[i].size(); j++) {
        //         cout << right[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
};
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    int q;
    cin>>q;

    SegmentTree st(a);

    // st.print_tree();


    for(int i = 0; i<q; i++){
        int l,r,x1;
        cin>>l>>r>>x1;
        l--;
        r--;
        int ans1 = st.query(l,r,x1);
        cout<<(r-l+1) - ans1<<endl;
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

