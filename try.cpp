/**
 *    author: Saurav
 *    created: 2024.10.20 19:16:04
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
class SegmentTree {
private:
    int n; // Size of the original array
    vector<int> tree; // Segment tree array
    vector<int> data; // Original array

    // Helper function to build the tree
    void buildTree(int pos, int left, int right) {
        if (left == right) {
            // Leaf node will have a single element
            tree[pos] = data[left];
            return;
        }
        int mid = left + (right - left) / 2;
        // Recursively build the left and right subtrees
        buildTree(2 * pos + 1, left, mid);
        buildTree(2 * pos + 2, mid + 1, right);
        // Internal node will have the maximum of its children
        tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    // Helper function to perform range maximum query
    int rangeMaxQuery(int pos, int left, int right, int ql, int qr) const {
        // If segment of this node is completely outside the query range
        if (qr < left || ql > right)
            return INT32_MIN; // Return minimum integer as it's irrelevant for max

        // If segment of this node is completely inside the query range
        if (ql <= left && right <= qr)
            return tree[pos];

        // If a part of this segment overlaps with the query range
        int mid = left + (right - left) / 2;
        int leftMax = rangeMaxQuery(2 * pos + 1, left, mid, ql, qr);
        int rightMax = rangeMaxQuery(2 * pos + 2, mid + 1, right, ql, qr);
        return max(leftMax, rightMax);
    }

    // Helper function to perform point update
    void pointUpdate(int pos, int left, int right, int idx, int value) {
        if (left == right) {
            // Leaf node. Update element.
            tree[pos] = value;
            data[idx] = value;
            return;
        }
        int mid = left + (right - left) / 2;
        if (idx <= mid)
            pointUpdate(2 * pos + 1, left, mid, idx, value);
        else
            pointUpdate(2 * pos + 2, mid + 1, right, idx, value);
        // Update current node based on children's values
        tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
    }

public:
    // Constructor to initialize the segment tree
    SegmentTree(const vector<int>& input) {
        data = input;
        n = data.size();
        // Allocate enough space for the segment tree
        // The maximum size of the segment tree is 2*(2^ceil(log2(n))) - 1
        int size = 1;
        while (size < n) size <<= 1;
        size = 2 * size - 1;
        tree.assign(size, INT32_MIN);
        buildTree(0, 0, n - 1);
    }

    // Function to perform range maximum query
    int rangeMax(int ql, int qr) const {
        if (ql < 0 || qr >= n || ql > qr) {
            throw invalid_argument("Invalid query range");
        }
        return rangeMaxQuery(0, 0, n - 1, ql, qr);
    }

    // Function to perform point update
    void update(int idx, int value) {
        if (idx < 0 || idx >= n) {
            throw invalid_argument("Index out of bounds");
        }
        pointUpdate(0, 0, n - 1, idx, value);
    }

    // Optional: Function to print the segment tree (for debugging)
    void printTree() const {
        for (int i = 0; i < tree.size(); ++i) {
            cout << tree[i] << ' ';
        }
        cout << '\n';
    }
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> input(n);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    vector<int> queries(m);
    for(int i=0;i<m;i++){
        cin>>queries[i];
    }
    SegmentTree st(input);

    for(int i = 0; i<m; i++){
        int val = queries[i];
        // debug(val);
        int lo = 0;
        int hi = n-1;
        int res = -1;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(st.rangeMax(0, mid) >= val){
                res = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        res = res + 1;

        cout<<res<<" ";

        if(res != 0){
            st.update(res-1, input[res-1] - val);
            input[res-1] = input[res-1] - val;
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

