/**
 *    author: Saurav
 *    created: 2024.10.28 14:10:54
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
void solve(){
    int n,kt;
    cin>>n>>kt;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    vector<int> v(n+1, 0);
    vector<SumSegmentTree> dp(kt+2, SumSegmentTree(v));
    vector<int> start(n+1, 0);
    vector<int> second(n+1, 1);
    second[0] = 0;
    dp[0] = SumSegmentTree(start);
    for(int i = 0; i<n; i++){
        int val = input[i];
        for(int k = 1; k<=kt+1; k++){
            if(k==1){
                dp[k].update(val, 1);
                continue;
            }
            int sumreq = dp[k-1].query(1, val-1);
            dp[k].update(val, sumreq);
        }
    }
    int ans = 0;
    ans = dp[kt+1].query(1, n);
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

