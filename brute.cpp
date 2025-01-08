/**
 *    author: Saurav
 *    created: 2025.01.08 12:57:34
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
int f(int a, int n, int cd){
    // S = n/2 * (2*a + (n-1)*d)

    return (n * (2*a + (n-1)*cd)) / 2;
}

class LazySegmentTree {
private:
    vector<int> st; // Segment Tree
    vector<int> lazy; // Lazy propagation array storing first term 
    vector<int> cdlazy; // store common difference  
    int n;

    // Build the segment tree
    void buildTree(const vector<int>& arr, int i, int lo, int hi) {
        if (lo == hi) {
            st[i] = arr[lo];
            return;
        }
        int mid = lo + (hi - lo) / 2;
        buildTree(arr, 2 * i + 1, lo, mid);
        buildTree(arr, 2 * i + 2, mid + 1, hi);
        st[i] = st[2 * i + 1] + st[2 * i + 2];
    }

    // Propagate lazy updates to children
    void propagate(int i, int lo, int hi) {
        if (lazy[i] != 0) {
            int range = hi - lo + 1;
            st[i] += f(lazy[i] , range, cdlazy[i]); // Apply lazy value to the current node

            if (lo != hi) { // Propagate to children if not a leaf
                lazy[2 * i + 1] += lazy[i];
                cdlazy[2 * i + 1] += cdlazy[i];
                int mid = lo + (hi - lo) / 2;
                int second = lazy[i] + (mid - lo + 1) * cdlazy[i];
                lazy[2 * i + 2] += second;
                cdlazy[2 * i + 2] += cdlazy[i];
            }

            lazy[i] = 0; // Clear the lazy value of the current node
            cdlazy[i] = 0;
        }
    }

    // Range increment update
    void updateRange(int i, int lo, int hi, int l, int r, int val = 1) {
        propagate(i, lo, hi); // Ensure the current node is updated

        if (l > hi || r < lo) return; // Out of range

        if (lo >= l && hi <= r) { // Fully within range
            lazy[i] += (lo - l + 1);// Add lazy update
            cdlazy[i] ++;
            propagate(i, lo, hi); // Apply the lazy operation
            return;
        }

        int mid = lo + (hi - lo) / 2;
        updateRange(2 * i + 1, lo, mid, l, r, val);
        updateRange(2 * i + 2, mid + 1, hi, l, r, val);
        st[i] = st[2 * i + 1] + st[2 * i + 2]; // Update the current node
    }

    // Range sum query
    int queryRange(int i, int lo, int hi, int l, int r) {
        propagate(i, lo, hi); // Ensure the current node is updated

        if (l > hi || r < lo) return 0; // Out of range

        if (lo >= l && hi <= r) return st[i]; // Fully within range

        int mid = lo + (hi - lo) / 2;
        int left = queryRange(2 * i + 1, lo, mid, l, r);
        int right = queryRange(2 * i + 2, mid + 1, hi, l, r);
        return left + right; // Combine results
    }

public:
    LazySegmentTree(const vector<int>& arr) {
        n = arr.size();
        st.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        cdlazy.resize(4 * n, 0);
        buildTree(arr, 0, 0, n - 1);

    }

    void updateRange(int l, int r, int val) {
        updateRange(0, 0, n - 1, l, r, val);
    }

    int queryRange(int l, int r) {
        return queryRange(0, 0, n - 1, l, r);
    }
};

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    LazySegmentTree st(a);

    while(q--){
        int type;
        cin>>type;
        if(type == 1){
            int a,b;
            cin>>a>>b;
            a--,b--;

            st.updateRange(a,b,1);
        }
        else{
            int a,b;
            cin>>a>>b;
            a--,b--;
            cout<<st.queryRange(a,b)<<endl;
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

