/**
 *    author: Saurav
 *    created: 2024.10.19 02:06:07
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
    int n;
    vector<vector<int>> tree;
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
    }

    // Helper function to merge two sorted vectors
    void mergeVectors(const vector<int> &left, const vector<int> &right, vector<int> &merged) {
        merged.resize(left.size() + right.size());
        int i = 0, j = 0, k = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                merged[k++] = left[i++];
            }
            else {
                merged[k++] = right[j++];
            }
        }

        // Copy remaining elements
        while (i < left.size()) {
            merged[k++] = left[i++];
        }
        while (j < right.size()) {
            merged[k++] = right[j++];
        }
    }

    // Function to perform the query
    int queryUtil(int node, int start, int end, int L, int R, int X) const {
        if (R < start || end < L) {
            // No overlap
            return 0;
        }

        if (L <= start && end <= R) {
            // Total overlap
            // Use binary search to find the count of X in tree[node]
            int left_idx = lower_bound(tree[node].begin(), tree[node].end(), X) - tree[node].begin();
            int right_idx = upper_bound(tree[node].begin(), tree[node].end(), X) - tree[node].begin();
            return right_idx - left_idx;
        }

        // Partial overlap
        int mid = start + (end - start) / 2;
        int left_child = 2 * node + 1;
        int right_child = 2 * node + 2;

        int count_left = queryUtil(left_child, start, mid, L, R, X);
        int count_right = queryUtil(right_child, mid + 1, end, L, R, X);

        return count_left + count_right;
    }

public:
    // Constructor to initialize and build the segment tree
    SegmentTree(const vector<int> &input_data) {
        data = input_data;
        n = data.size();
        // Allocate enough space for the segment tree
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    // Function to query the frequency of X in range [L, R]
    int query(int L, int R, int X) const {
        if (L < 0 || R >= n || L > R) {
            throw invalid_argument("Invalid query range.");
        }
        return queryUtil(0, 0, n - 1, L, R, X);
    }
};


bool poss(int mid , vector<int> &prfsum , int last, int reqsum){
    if(prfsum[last] - ((mid - 1 >=0 ) ? prfsum[mid-1] : 0) <= reqsum) return false;

    return true;   
}

vector<int> previousunequalelements(vector<int> &input){
    int n = input.size();
    vector<int> ans(n+1, -1);
    stack<pp> st;
    for(int i = 0; i<n; i++){
        while(!st.empty() && st.top().first == input[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top().second;
        }
        st.push({input[i], i});
    }
    return ans;
}

vector<int> nextunequalelement(vector<int> &input){
    int n = input.size();
    vector<int> ans(n+1, n);
    stack<pp> st;
    for(int i = n-1; i>=0; i--){
        while(!st.empty() && st.top().first == input[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top().second;
        }
        st.push({input[i], i});
    }
    return ans;
}


void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    vector<int> prfsum(n,0);
    prfsum[0] = input[0];
    for(int i = 1; i<n; i++){
        prfsum[i] = prfsum[i-1] + input[i];
    }


    vector<int> pre = previousunequalelements(input);
    vector<int> nxt = nextunequalelement(input);

    print(pre);

    // SegmentTree st(input);
    for(int i = 0; i<n; i++){

        if(i-1>=0 and input[i-1] > input[i]){
            cout<<1<<" ";
            continue;
        }
        if(i+1<n and input[i+1] > input[i]){
            cout<<1<<" ";
            continue;
        }

        int loleft = 0;
        int hileft = i-1;
        int resleft = 1e15;
        while(loleft <= hileft){
            int mid = (loleft + hileft) / 2;

            int lastunequal = pre[i-1];

            if(lastunequal == -1){
                break;
            }
            
            if(mid > lastunequal){
                hileft = mid-1;
                continue;
            }

            if(poss(mid, prfsum, i-1, input[i])) {
                resleft = i-1-mid+1;
                loleft = mid+1;
            }
            else{
                hileft = mid-1;
            }
        }

        int loright = i+1;
        int hiright = n-1;
        int resright = 1e15;
        while(loright <= hiright){
            int mid = (loright + hiright) / 2;

            int lastunequal = nxt[i+1];

            if(mid < lastunequal){
                loright = mid+1;
                continue;
            }

            if(poss(i+1, prfsum, mid, input[i])){
                resright = mid-i-1+1;
                hiright = mid-1;
            }
            else{
                loright = mid+1;
            }
        }

        debug(i);
        debug(resleft);
        debug(resright);

        int ans = min(resleft, resright);
        if(ans >= 1e14) ans = -1;  
        cout<<ans<<" ";
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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

