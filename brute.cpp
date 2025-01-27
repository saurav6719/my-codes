/**
 *    author: Saurav
 *    created: 2025.01.26 21:09:00
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
            return INT32_MIN;
        }
        return rangeMaxQuery(0, 0, n - 1, ql, qr);
    }

    // Function to perform point update
    void update(int idx, int value) {
        if (idx < 0 || idx >= n) {
            throw invalid_argument("Invalid index");
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

void eulerstour(vector<vector<int>> &tree, int node, int par, vector<int> &tour){
    tour.push_back(node);
    for(auto child : tree[node]){
        if(child != par){
            eulerstour(tree, child, node, tour);
        }
    }
    tour.push_back(node);
}

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

class TreeQuery {
private:
    int n; // Number of nodes
    vector<vector<int>> tree; // Adjacency list representation of the tree
    vector<int> values; // Node values
    vector<int> euler; // Euler tour of the tree
    vector<int> start, end; // Start and end times of each node in the Euler tour
    vector<int> fenwick; // Fenwick Tree for frequency of values
    map<int, int> valueToIndex; // Coordinate compression map
    int timer;

    void dfs(int node, int parent) {
        start[node] = timer++;
        euler.push_back(values[node]);
        for (int neighbor : tree[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node);
            }
        }
        end[node] = timer - 1;
    }

    void updateFenwick(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx) {
            fenwick[idx] += delta;
        }
    }

    int queryFenwick(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += fenwick[idx];
        }
        return sum;
    }

public:
    TreeQuery(int n, const vector<vector<int>>& tree, const vector<int>& values)
        : n(n), tree(tree), values(values), start(n + 1), end(n + 1), fenwick(n + 1, 0) {
        // Coordinate compression of values
        vector<int> sortedValues(values.begin() + 1, values.end());
        sort(sortedValues.begin(), sortedValues.end());
        int index = 1;
        for (int value : sortedValues) {
            if (valueToIndex.find(value) == valueToIndex.end()) {
                valueToIndex[value] = index++;
            }
        }

        // Prepare the Euler tour
        timer = 1;
        dfs(1, -1);

        // Build the Fenwick Tree based on the initial values
        for (int i = 1; i <= n; ++i) {
            updateFenwick(valueToIndex[values[i]], 1);
        }
    }

    int query(int node) {
        int value = values[node];
        int compressedValue = valueToIndex[value];

        // Total count of values greater than the current node's value
        int totalGreater = queryFenwick(n) - queryFenwick(compressedValue);

        // Count of values greater than the current node's value within its subtree
        int subtreeGreater = 0;
        for (int i = start[node]; i <= end[node]; ++i) {
            if (valueToIndex[euler[i - 1]] > compressedValue) {
                subtreeGreater++;
            }
        }

        return totalGreater - subtreeGreater;
    }
};


void solve(){
    int n;
    cin>>n;
    vector<int> values(n+1);
    for(int i=1;i<=n;i++){
        cin>>values[i];
    }

    vector<vector<int> > tree(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> tour;

    eulerstour(tree, 1, 0, tour);

    print(tour);

    vector<int> valuesattour;
    for(auto node : tour){
        valuesattour.push_back(values[node]);
    }

    map<int, int> first_occurence;  
    for(int i=0;i<tour.size();i++){
        if(first_occurence.find(tour[i]) == first_occurence.end()){
            first_occurence[tour[i]] = i;
        }
    }

    // printmap(first_occurence);

    map<int, int> last_occurence;
    for(int i=tour.size()-1;i>=0;i--){
        if(last_occurence.find(tour[i]) == last_occurence.end()){
            last_occurence[tour[i]] = i;
        }
    }

    // printmap(last_occurence);

    set<int> loosingpos;

    SegmentTree st(valuesattour);

    vector<int> pos(tour.size(), 0);

    int maxvalue = *max_element(values.begin(), values.end());

    debug(maxvalue);

    for(int i = 1; i<=n; i++){
        if(values[i] == maxvalue){
            pos[first_occurence[i]] = 1;
            pos[last_occurence[i]] = 1;
        }
    }

    print(pos);

    SumSegmentTree sst(pos);

    vector<pp> inputwithvalidx(n+1);
    for(int i=1;i<=n;i++){
        inputwithvalidx[i] = {values[i], i};
    }



    map<int,vector<int>> mp5;
    for(int i=1;i<=n;i++){
        mp5[values[i]].push_back(i);
    }

    sort(inputwithvalidx.begin(), inputwithvalidx.end(), greater<pp>());

    TreeQuery tq(n, tree, values);

    map<int,vector<int> > mp6;


    for(auto ele : inputwithvalidx){
        int value = ele.first;
        int idx = ele.second;

        if(!mp6.empty()){

            
            int maxval = mp6.begin()->first;

            if(idx == 2){
                // cout<<"akhda"<<endl;
                debug(maxval);
            }
            if(maxval > value){
                for(auto ele : mp6[maxval]){
                    int ff1 = first_occurence[ele];
                    int ll1 = last_occurence[ele];
                    sst.update(ff1, 1);
                    sst.update(ll1, 1);
                    debug(ele);
                }
            }

            mp6.erase(maxval);
        }



        if(value == maxvalue){
            continue;
        }

        debug(idx);
        debug(value);

        int iskebahar = tq.query(idx);

        if(iskebahar == 0){
            mp6[value].push_back(idx);
            continue;
        }

        debug(iskebahar);

        int ff = first_occurence[idx];
        int ll = last_occurence[idx];

        int leftsum = sst.query(0, ff-1);
        int rightsum = sst.query(ll+1, tour.size()-1);

        debug(leftsum);
        debug(rightsum);

        if((leftsum + rightsum) == 2*iskebahar){
            cout<<idx<<endl;
            return;
        }
    }

    cout<<0<<endl;
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
 