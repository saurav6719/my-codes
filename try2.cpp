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
using namespace std;

/* write core logic here */
struct node{
    vector<int> count;
    int total;
};

vector<node> segmenttree;
vector<int> input;
int k;

void build(int i, int lo, int hi){
    if(lo == hi){
        segmenttree[i].count.resize(k);
        segmenttree[i].count[input[lo] % k]++;
        segmenttree[i].total = input[lo] % k;
        return;
    }
    int mid = (lo + hi) / 2;
    build(2*i + 1, lo, mid);
    build(2*i + 2, mid + 1, hi);
    segmenttree[i].count.clear();
    segmenttree[i].count.resize(k);
    vector<int> &leftcount = segmenttree[2*i + 1].count;
    vector<int> &rightcount = segmenttree[2*i + 2].count;
    for(int a = 0; a<k; a++){
        segmenttree[i].count[a] = leftcount[a];
    }
    int total = segmenttree[2*i + 1].total;
    for(int a = 0; a<k; a++){
        int newval;
        
        newval = (total * a) % k;
        segmenttree[i].count[newval] += rightcount[a];
    }

    int lefttotal = segmenttree[2*i + 1].total;
    int righttotal = segmenttree[2*i + 2].total;

    segmenttree[i].total = (lefttotal * righttotal) % k;
}

void pointupdate(int i, int lo, int hi, int idx, int val){
    if(lo == hi){
        segmenttree[i].count.clear();
        segmenttree[i].count.resize(k);
        segmenttree[i].count[input[lo] % k]++;
        segmenttree[i].total = input[lo] % k;
        return;
    }

    int mid = (lo + hi) / 2;
    if(idx <= mid){
        pointupdate(2*i + 1, lo, mid, idx, val);
    }
    else{
        pointupdate(2*i + 2, mid + 1, hi, idx, val);
    }
    segmenttree[i].count.clear();
    segmenttree[i].count.resize(k);
    vector<int> &leftcount = segmenttree[2*i + 1].count;
    vector<int> &rightcount = segmenttree[2*i + 2].count;
    for(int a = 0; a<k; a++){
        segmenttree[i].count[a] = leftcount[a];
    }
    int total = segmenttree[2*i + 1].total;
    for(int a = 0; a<k; a++){
        int newval;
        
        newval = (total * a) % k;
        segmenttree[i].count[newval] += rightcount[a];
    }

    int lefttotal = segmenttree[2*i + 1].total;
    int righttotal = segmenttree[2*i + 2].total;
    segmenttree[i].total = (lefttotal * righttotal) % k;
}

int query(int i, int lo, int hi, int l,int r, int x, int &prevtotal, int k){
    // l se n-1 tak me how many cnt[x]

    // out of range 
    if(l > hi || r < lo){
        return 0;
    }

    int chahiye = -1;
    if(prevtotal == -1) chahiye = x;
    else{
        for(int a = 0; a<k; a++){
            if((prevtotal * a) % k == x){
                chahiye = a;
                break;
            }
        }
    }
    // completely in range

    if(l <= lo && hi <= r){
        prevtotal *= segmenttree[i].total;
        prevtotal %= k;
        if(chahiye == -1) return 0;
        return segmenttree[i].count[chahiye];
    }
    // partially in range
    int mid = (lo + hi) / 2;

    int left = query(2*i + 1, lo, mid, l, r, x, prevtotal, k);
    int right = query(2*i + 2, mid + 1, hi, l,r, x, prevtotal, k);

    if(x == 0 and left > 0){
        return left + (hi - mid);
    }

    return left + right;    

}

vector<int> resultArray(vector<int>& nums, int k1, vector<vector<int>>& queries) {
    int n = nums.size();
    input = nums;
    k = k1;
    segmenttree.resize(4*n);
    build(0, 0, n - 1);
    vector<int> result;

    for(auto ele : queries){
        int idx = ele[0];
        int val = ele[1];
        input[idx] = val;
        pointupdate(0, 0, n - 1, idx, val);

        int l = ele[2];
        int x = ele[3];

        int prevtotal = -1;

        int ans = query(0, 0, n - 1, l,n-1,  x, prevtotal, k);
        result.push_back(ans);
    }

    return result;

}


void solve(){
    int n;
    cin>>n;

    int k1;
    cin>>k1;

    vector<int> nums(n);

    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }

    int q;
    cin>>q;

    vector<vector<int>> queries(q, vector<int>(4));

    for(int i = 0; i<q; i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;

        queries[i][0] = a;
        queries[i][1] = b;
        queries[i][2] = c;
        queries[i][3] = d;

    }

    vector<int> result = resultArray(nums, k1, queries);

    for(auto ele : result){
        cout<<ele<<endl;
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

