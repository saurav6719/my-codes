/**
 *    author: Saurav
 *    created: 2025.02.01 17:26:27
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
#define minf -1e18
#define inf 1e18
using namespace std;

/* write core logic here */

struct node{
    int answer;
    int rangemin;
    int rangemax;
};

vector<node> segment_tree;

void build(int index, int l, int r, vector<int> &arr){
    if(l == r){
        segment_tree[index].answer = minf;
        segment_tree[index].rangemin = arr[l];
        segment_tree[index].rangemax = arr[l];
        return;
    }

    int mid = (l + r) / 2;

    build(2 * index + 1, l, mid, arr);
    build(2 * index + 2, mid + 1, r, arr);

    segment_tree[index].answer = mx(segment_tree[2 * index + 1].answer, segment_tree[2 * index + 2].answer, segment_tree[2 * index + 2].rangemax - segment_tree[2 * index + 1].rangemin);
    segment_tree[index].rangemin = min(segment_tree[2 * index + 1].rangemin, segment_tree[2 * index + 2].rangemin);
    segment_tree[index].rangemax = max(segment_tree[2 * index + 1].rangemax, segment_tree[2 * index + 2].rangemax);

}

void update(int index,int lo, int hi, int idx, int val, vector<int> &arr){
    if(lo == hi){
        arr[idx] = val;
        segment_tree[index].rangemin = val;
        segment_tree[index].rangemax = val;
        return;
    }

    int mid = (lo + hi) / 2;

    if(idx <= mid){
        update(2 * index + 1, lo, mid, idx, val, arr);
    }else{
        update(2 * index + 2, mid + 1, hi, idx, val, arr);
    }

    segment_tree[index].answer = mx(segment_tree[2 * index + 1].answer, segment_tree[2 * index + 2].answer, segment_tree[2 * index + 2].rangemax - segment_tree[2 * index + 1].rangemin);
    segment_tree[index].rangemin = min(segment_tree[2 * index + 1].rangemin, segment_tree[2 * index + 2].rangemin);
    segment_tree[index].rangemax = max(segment_tree[2 * index + 1].rangemax, segment_tree[2 * index + 2].rangemax);

}

int query(){
    return segment_tree[0].answer;
}

void solve(){
    segment_tree.clear();
    int n;
    cin>>n;
    int q;
    cin>>q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    segment_tree.resize(4 * n);

    build(0, 0, n - 1, arr);

    cout<<query()<<" ";

    while(q--){
        int idx, val;
        cin>>idx>>val;
        idx--;
        update(0, 0, n - 1, idx, val, arr);
        cout<<query()<<" ";
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}