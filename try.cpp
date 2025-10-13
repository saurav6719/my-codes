/**
 *    author: Saurav
 *    created: 2025.10.14 01:30:01
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

vector<int> ans(vector<int> &v, int n, vector<pp> &queries){
    class SumSegmentTree {
    private:
        std::vector<int> tree;
        int n;
    
        // Build the segment tree from the initial array
        void build(const std::vector<int> &arr, int node, int start, int end) {
            if (start == end) {
                // Leaf node
                tree[node] = arr[start];
            } else {
                int mid = (start + end) / 2;
                build(arr, 2 * node + 1, start, mid);        // Build left subtree
                build(arr, 2 * node + 2, mid + 1, end);      // Build right subtree
                tree[node] = tree[2 * node + 1] + tree[2 * node + 2];  // Sum of left and right
            }
        }
    
        // Update an element in the segment tree
        void update(int node, int start, int end, int idx, int value) {
            if (start == end) {
                // Leaf node
                tree[node] = value;
            } else {
                int mid = (start + end) / 2;
                if (idx <= mid) {
                    // Update left child
                    update(2 * node + 1, start, mid, idx, value);
                } else {
                    // Update right child
                    update(2 * node + 2, mid + 1, end, idx, value);
                }
                tree[node] = tree[2 * node + 1] + tree[2 * node + 2];  // Recalculate sum
            }
        }
    
        // Query the sum of a range
        int query(int node, int start, int end, int L, int R) {
            if (R < start || end < L) {
                return 0;  // Out of range
            }
            if (L <= start && end <= R) {
                return tree[node];  // Fully within range
            }
            int mid = (start + end) / 2;
            int leftSum = query(2 * node + 1, start, mid, L, R);
            int rightSum = query(2 * node + 2, mid + 1, end, L, R);
            return leftSum + rightSum;
        }
    
    public:
        // Constructor to initialize the segment tree
        SumSegmentTree(const std::vector<int> &arr) {
            n = arr.size();
            tree.resize(4 * n);
            build(arr, 0, 0, n - 1);
        }
    
        // Update a specific index with a new value
        void update(int idx, int value) {
            update(0, 0, n - 1, idx, value);
        }
    
        // Query the sum in the range [L, R]
        int query(int L, int R) {
            return query(0, 0, n - 1, L, R);
        }
    };
    int q = queries.size();
    map<int,int> last_index;
    vector<int> arr(n,0);
    SumSegmentTree seg(arr);
    vector<int> res(q);
    map<int,vector<int> > indices; // map representing queries ending at r
    for(int i = 0; i<q; i++){
        indices[queries[i].second].push_back(i);
    }

    for(int i = 0; i<n; i++){
        if(last_index.find(v[i]) == last_index.end()){
            seg.update(i, 1);
            last_index[v[i]] = i;
        }
        else{
            int last_idx = last_index[v[i]];
            seg.update(last_idx, 0);
            seg.update(i, 1);
            last_index[v[i]] = i;
        }

        // check for any query ending at this i 
        if(indices.find(i) != indices.end()){
            for(auto idx : indices[i]){
                int l = queries[idx].first;
                int r = i;
                // answer is prefix sum between l and r
                res[idx] = seg.query(l, r);
            }
        }
    }
    return res;
}
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    int q;
    cin>>q;
    vector<pp> queries(q);
    for(int i = 0; i<q; i++){
        cin>>queries[i].first>>queries[i].second;
    }

    for(int i = 0; i<q; i++){
        queries[i].first--;
        queries[i].second--;
    }
    vector<int> res = ans(v, n, queries);
    for(auto ele : res){
        cout<<ele<<endl;
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

