/**
 *    author: Saurav
 *    created: 2025.01.04 22:14:07
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
class LazySegTree {
private:
    int n;
    vector<long long> tree, lazy;

    void apply(int node, int start, int end, long long value) {
        tree[node] += value;
        if (start != end) {
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
    }

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            apply(node, start, end, lazy[node]);
            lazy[node] = 0;
        }
    }

    void build(const vector<long long>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, node * 2, start, mid);
            build(arr, node * 2 + 1, mid + 1, end);
            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    void updateRange(int node, int start, int end, int l, int r, long long value) {
        propagate(node, start, end);

        if (start > r || end < l) return;

        if (start >= l && end <= r) {
            apply(node, start, end, value);
            return;
        }

        int mid = (start + end) / 2;
        updateRange(node * 2, start, mid, l, r, value);
        updateRange(node * 2 + 1, mid + 1, end, l, r, value);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    long long queryRange(int node, int start, int end, int l, int r) {
        propagate(node, start, end);

        if (start > r || end < l) return LLONG_MIN;

        if (start >= l && end <= r) return tree[node];

        int mid = (start + end) / 2;
        long long leftMax = queryRange(node * 2, start, mid, l, r);
        long long rightMax = queryRange(node * 2 + 1, mid + 1, end, l, r);

        return max(leftMax, rightMax);
    }

public:
    LazySegTree(const vector<long long>& arr) {
        n = arr.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    void update(int l, int r, long long value) {
        updateRange(1, 0, n - 1, l, r, value);
    }

    long long query(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }
};

class SegmentTree {
private:
    int n;
    vector<long long> tree;

    void build(const vector<long long>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, node * 2, start, mid);
            build(arr, node * 2 + 1, mid + 1, end);
            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    void updatePoint(int node, int start, int end, int idx, long long value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                updatePoint(node * 2, start, mid, idx, value);
            } else {
                updatePoint(node * 2 + 1, mid + 1, end, idx, value);
            }
            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    long long queryRange(int node, int start, int end, int l, int r) {
        if (start > r || end < l) return LLONG_MIN;

        if (start >= l && end <= r) return tree[node];

        int mid = (start + end) / 2;
        long long leftMax = queryRange(node * 2, start, mid, l, r);
        long long rightMax = queryRange(node * 2 + 1, mid + 1, end, l, r);

        return max(leftMax, rightMax);
    }

public:
    SegmentTree(const vector<long long>& arr) {
        n = arr.size();
        tree.resize(4 * n, LLONG_MIN);
        build(arr, 1, 0, n - 1);
    }

    void update(int idx, long long value) {
        updatePoint(1, 0, n - 1, idx, value);
    }

    long long query(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }
};

void solve(){
    int n,q;
    cin>>n>>q;vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    vector<int> one(n);
    one[n-1] = -1e15;
    vector<int> two(n);
    two[0] = -1e15;
    vector<int> v1;
    for(int i = 1; i<n; i++){
        v1.push_back(input[0] - input[i] - i);
    }
    print(v1);

    LazySegTree st1(v1);

    for(int i = 0; i<n-1; i++){
        one[i] = st1.query(i, v1.size() - 1);
        int valueupd;
        int x = input[i] - input[i+1];
        x--;
        x*= -1;
        debug(x);
        debug(i);
        st1.update(i+1, v1.size() - 1, x);
    }

    print(one);

    vector<int> v2;

    for(int i = n-2; i>=0; i--){
        v2.push_back(input[n-1] - input[i] - (n-1-i));
    }

    reverse(v2.begin(), v2.end());

    print(v2);

    LazySegTree st2(v2);

    for(int i = n-1; i>0; i--){
        two[i] = st2.query(0, i);
        int valueupd;
        int x = input[i] - input[i+1];
        x++;
        debug(x);
        debug(i);
        x*= -1;
        st2.update(0, i-1, x);
    }

    print(two);

    vector<int> ans;


    SegmentTree st3(one);
    SegmentTree st4(two);

    print(one);
    print(two);

    int x1 = st3.query(0, n-1);
    int x2 = st4.query(0, n-1);

    int maxi = max(x1, x2);
    ans.push_back(maxi);    

    while(q--){
        int x,d;
        cin>>x>>d;
        x--;

        int actual = input[x];
        int newval = d;

        int diff = newval - actual;

        input[x] = newval;

        int actualinone = one[x];
        int actualintwo = two[x];

        int newinone = actualinone + diff;
        int newintwo = actualintwo + diff;

        one[x] = newinone;
        two[x] = newintwo;

        print(one);
        print(two);

        st3.update(x, newinone);
        st4.update(x, newintwo);

        int xx1 = st3.query(0, n-1);
        int xx2 = st4.query(0, n-1);

        int maxxi = max(xx1, xx2);

        ans.push_back(maxi);

    }

    for(auto x : ans){
        cout<<x<<endl;
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

