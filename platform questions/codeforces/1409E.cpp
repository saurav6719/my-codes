/**
 *    author: Saurav
 *    created: 2024.10.16 17:16:15
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

class MaxSegmentTree {
private:
    int n; // Size of the original array
    vector<int> tree; // Segment tree array
    vector<int> arr; // Original array

    // Helper function to build the segment tree
    void build(int node, int start, int end) {
        if (start == end) {
            // Leaf node will have a single element
            tree[node] = arr[start];
        }
        else {
            int mid = start + (end - start) / 2;
            // Recursively build the left and right children
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            // Internal node will have the maximum of its children
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    // Helper function to perform range maximum query
    int queryMax(int node, int start, int end, int l, int r) const {
        if (r < start || end < l) {
            // Range represented by a node is completely outside the given range
            return INT32_MIN; // Represents negative infinity
        }
        if (l <= start && end <= r) {
            // Range represented by a node is completely inside the given range
            return tree[node];
        }
        // Range represented by a node is partially inside and partially outside the given range
        int mid = start + (end - start) / 2;
        int p1 = queryMax(2 * node, start, mid, l, r);
        int p2 = queryMax(2 * node + 1, mid + 1, end, l, r);
        return max(p1, p2);
    }

    // Helper function to update a value at a specific position
    void updateValue(int node, int start, int end, int idx, int val) {
        if (start == end) {
            // Leaf node
            arr[idx] = val;
            tree[node] = val;
        }
        else {
            int mid = start + (end - start) / 2;
            if (start <= idx && idx <= mid) {
                // If idx is in the left child, recurse on the left child
                updateValue(2 * node, start, mid, idx, val);
            }
            else {
                // If idx is in the right child, recurse on the right child
                updateValue(2 * node + 1, mid + 1, end, idx, val);
            }
            // Internal node will have the maximum of its children
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

public:
    // Constructor to initialize the segment tree with the given array
    MaxSegmentTree(const vector<int>& input) {
        arr = input;
        n = arr.size();
        // Initialize the segment tree with enough space (4*n is a safe size)
        tree.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    // Function to perform a range maximum query from index l to r (0-based indexing)
    int queryMax(int l, int r) const {
        if (l < 0 || r >= n || l > r) {
            throw invalid_argument("Invalid query range");
        }
        return queryMax(1, 0, n - 1, l, r);
    }

    // Function to update the value at index idx to val (0-based indexing)
    void updateValue(int idx, int val) {
        if (idx < 0 || idx >= n) {
            throw out_of_range("Index out of range");
        }
        updateValue(1, 0, n - 1, idx, val);
    }

    // Optional: Function to print the segment tree (for debugging)
    void printTree() const {
        for (int i = 1; i < tree.size(); ++i) {
            cout << tree[i] << " ";
        }
        cout << "\n";
    }
};


/* write core logic here */
void solve(){
    int n,k;
    cin
    >>n>>k;
    vector<int> x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    vector<int> y(n);
    for(int i=0;i<n;i++){
        cin>>y[i];
    }
    sort(x.begin(),x.end());
    vector<int> length;

    vector<int> end;
    for(int i = 0;i<n ; i++){
        int starting = x[i];
        int ending = x[i] + k;
        int idx = upper_bound(x.begin(),x.end(),ending) - x.begin();
        end.push_back(idx-1);

        length.push_back(idx - i);
    }

    MaxSegmentTree st(end);

    vector<int> maxi(n);
    maxi[n-1] = length[n-1];
    
    for(int i = n-2; i>=0; i--){
        maxi[i] = max(maxi[i+1],length[i]);
    }

    print(length);
    print(end);
    print(maxi);

    int ans = 0;
    for(int i = 0; i<n; i++){
        int lasti = end[i];
        int curr = length[i] + (lasti+1<n ? maxi[lasti+1] : 0);

        int last = st.queryMax(i, end[i]);

        curr = max(curr , last - i + 1);
        ans = max(ans,curr);
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

