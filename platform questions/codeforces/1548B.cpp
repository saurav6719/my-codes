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

// Function to compute GCD
int gcd_func(int a, int b) {
    return b == 0 ? a : gcd_func(b, a % b);
}

// Segment Tree Class
class SegmentTree {
private:
    int n; // Size of the array
    vector<int> tree; // Segment Tree
    vector<int> data; // Original array

    // Build the Segment Tree
    void build(int node, int start, int end) {
        if (start == end) {
            // Leaf node will have a single element
            tree[node] = data[start];
            // Debug statement
            // cout << "Built leaf node at index " << node << " with value " << data[start] << "\n";
        }
        else {
            int mid = start + (end - start) / 2;
            // Recurse on the left child
            build(2 * node, start, mid);
            // Recurse on the right child
            build(2 * node + 1, mid + 1, end);
            // Internal node will have the GCD of both children
            tree[node] = gcd_func(tree[2 * node], tree[2 * node + 1]);
            // Debug statement
            // cout << "Built internal node at index " << node << " with GCD(" << tree[2 * node] << ", " << tree[2 * node + 1] << ") = " << tree[node] << "\n";
        }
    }

    // Query the Segment Tree for GCD in range [L, R]
    int query_util(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            // No overlap
            return 0; // Since GCD(x, 0) = x
        }
        if (L <= start && end <= R) {
            // Total overlap
            return tree[node];
        }
        // Partial overlap
        int mid = start + (end - start) / 2;
        int p1 = query_util(2 * node, start, mid, L, R);
        int p2 = query_util(2 * node + 1, mid + 1, end, L, R);
        if (p1 == 0) return p2;
        if (p2 == 0) return p1;
        return gcd_func(p1, p2);
    }

public:
    // Constructor
    SegmentTree(vector<int> &input_data) {
        data = input_data;
        n = data.size();
        // Initialize the tree with 4n size
        tree.resize(4 * n, 0);
        // Build the tree
        build(1, 0, n - 1);
    }

    // Function to query GCD in range [L, R]
    int query(int L, int R) {
        // Ensure the indices are within bounds
        if (L < 0) L = 0;
        if (R >= n) R = n - 1;
        return query_util(1, 0, n - 1, L, R);
    }

    // (Optional) Function to update a value at position idx
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            // Leaf node
            data[idx] = val;
            tree[node] = val;
        }
        else {
            int mid = start + (end - start) / 2;
            if (idx <= mid)
                update(2 * node, start, mid, idx, val);
            else
                update(2 * node + 1, mid + 1, end, idx, val);
            tree[node] = gcd_func(tree[2 * node], tree[2 * node + 1]);
        }
    }
};

void solve(){
    int n;
    cin>>n;vector<int> input(n);


    for(int i = 0; i<n; i++){
        cin>>input[i];
    }


    if(n==1) {
        cout<<1<<endl;
        return;
    }

    vector<int> diff;
    for(int i = 1; i<n; i++){
        diff.push_back(abs(input[i] - input[i-1]));
    }

    SegmentTree st(diff);

    int ans = 1;

    for(int i = 0; i<n-1; i++){
        int lo = i; int hi = n-2;
        int curr = -1;

        while(lo <= hi){
            int mid = (lo+hi) / 2;

            int xx = st.query(i, mid);
            if(xx > 1){
                curr = mid;
                lo = mid +1;
            }
            else hi = mid -1;
        }

        if(curr == -1) continue;

        debug(i);
        debug(curr);
        
        ans = max(ans , (curr - i+2));
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

