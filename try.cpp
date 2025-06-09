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
#define printset(s)
#define printpp(v)
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

SegmentTree *stt;
void solve(){
    int n;
    cin>>n;
    set<int> st;
    set<pp> st2;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        st.insert(v[i]);
    }
    v.push_back(1e9);
    st.insert(1e9);
    st.insert(0);

    set<int> updateset;

    for(int i = 0; i<n; i++){
        st2.insert({v[i+1] - v[i] - 1 , v[i]+1});
        stt->update(v[i]+1 , v[i+1] - v[i] - 1);
        updateset.insert(v[i]+1);
    }
    stt->update(1, v[0] - 1);
    updateset.insert(1);
    int q;
    cin>>q;
    while(q--){
        
        char type;
        cin>>type;
        if(type == '+'){
            int x;
            cin>>x;
            // add this to set
            auto lb = st.lower_bound(x);
            int justbada = *lb;
            lb--;
            int justpehle = *lb;
            pp y = {justbada - justpehle - 1, justpehle + 1};
            st2.erase(y);
            stt->update(justpehle + 1, -1e9);
            updateset.erase(justpehle + 1);
            st.insert(x);
            {
                int dist = x - justpehle - 1;
                int start = justpehle + 1;
                st2.insert({dist, start});
                stt->update(start, dist);
                updateset.insert(start);
            }
            {
                int dist = justbada - x - 1;
                int start = x + 1;
                st2.insert({dist, start});
                stt->update(start, dist);
                updateset.insert(start);
            }
        }
        if(type == '-'){
            int x;
            cin>>x;
            // remove this from set
            st.erase(x);
            auto lb = st.lower_bound(x);
            int justbada = *lb;
            lb--;
            int justpehle = *lb;
            debug(justbada);
            debug(justpehle);
            {
                int dist = x - justpehle - 1;
                int start = justpehle + 1;
                debug(dist);
                debug(start);
                st2.erase({dist, start});
                stt->update(start, -1e9);
                updateset.erase(start);
            }
            {
                int dist = justbada - x - 1;
                int start = x + 1;
                debug(dist);
                debug(start);
                st2.erase({dist, start});
                stt->update(start, -1e9);
                updateset.erase(start);
            }
            st2.insert({justbada - justpehle - 1, justpehle + 1});
            stt->update(justpehle + 1, justbada - justpehle - 1);
            updateset.insert(justpehle + 1);
        }

        if(type == '?'){
            int x;
            cin>>x;
            int lo = 1, hi = 2e6 + 1;
            int ans = -1;
            while(lo <= hi){
                int mid = (lo + hi) / 2;
                if(stt ->rangeMax(1, mid) >= x){
                    ans = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            cout<<ans<<" ";
        }
    }

    for(auto ele : updateset){
        if(ele >= 0 and ele <= 2e6+3) stt -> update(ele, -1e9);
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
    cin>>t;

    vector<int> v(2e6+5, -1e9);

    stt = new SegmentTree(v);
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

