/**
 *    author: Saurav
 *    created: 2025.10.14 04:49:36
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
#define printpp(v)
#define printset(s)
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
struct node{
    int min;
    int max;
    int ans;
};

vector<node> segment_tree;

void build(int i, int lo, int hi, vector<int> &v, int n){
    if(lo == hi){
        segment_tree[i].min = v[lo];
        segment_tree[i].max = v[lo];
        segment_tree[i].ans = -1e15;
        return;
    }
    int mid = lo + (hi - lo)/2;
    build(2*i+1, lo, mid, v, n);
    build(2*i+2, mid+1, hi, v, n);
    segment_tree[i].min = min(segment_tree[2*i+1].min, segment_tree[2*i+2].min);
    segment_tree[i].max = max(segment_tree[2*i+1].max, segment_tree[2*i+2].max);
    segment_tree[i].ans = max({segment_tree[2*i+1].ans, segment_tree[2*i+2].ans});
    segment_tree[i].ans = max(segment_tree[i].ans, segment_tree[2*i+2].max - segment_tree[2*i+1].min);
}

void update(int i, int lo, int hi, int idx, int value){
    if(lo == hi){
        segment_tree[i].min = value;
        segment_tree[i].max = value;
        segment_tree[i].ans = -1e15;
        return;
    }
    int mid = lo + (hi - lo)/2;
    if(idx <= mid){
        update(2*i+1, lo, mid, idx, value);
    }
    else{
        update(2*i+2, mid+1, hi, idx, value);
    }
    segment_tree[i].min = min(segment_tree[2*i+1].min, segment_tree[2*i+2].min);
    segment_tree[i].max = max(segment_tree[2*i+1].max, segment_tree[2*i+2].max);
    segment_tree[i].ans = max({segment_tree[2*i+1].ans, segment_tree[2*i+2].ans});
    segment_tree[i].ans = max(segment_tree[i].ans, segment_tree[2*i+2].max - segment_tree[2*i+1].min);
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }

    vector<int> arr(n);
    segment_tree.resize(4*n);

    for(int i = 0; i<n; i++){
        arr[i] = v[i];
    }

    build(0, 0, n-1, arr, n);
    cout<<segment_tree[0].ans<<" ";

    while(q--){
        int idx, value;
        cin>>idx>>value;
        idx--;
        update(0, 0, n-1, idx, value);
        cout<<segment_tree[0].ans<<" ";
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

