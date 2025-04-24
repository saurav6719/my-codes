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
vector<int> segment_tree;
void build_segment_tree(int i , int lo, int hi , vector<int> &input){
    if(lo == hi){
        segment_tree[i] = input[lo];
        return;
    }
    int mid = lo + (hi - lo )/2;

    build_segment_tree(2*i+1, lo , mid, input);
    build_segment_tree(2*i+2, mid+1, hi, input);

    segment_tree[i] = (segment_tree[2*i+1] + segment_tree[2*i+2]);
}

void update(int idx_to_update, int i, int lo, int hi , int val_to_update){
    if(lo == hi){
        segment_tree[i] = val_to_update;
        return;
    }
    int mid = lo +( hi - lo) / 2;

    if(idx_to_update <= mid){
        update(idx_to_update, 2*i+1, lo, mid, val_to_update);
    }
    else{
        update(idx_to_update, 2*i+2, mid+1, hi, val_to_update);
    }

    segment_tree[i] = segment_tree[2*i+1] + segment_tree[2*i+2];
}

int get_sum(int i, int lo , int hi , int &l ,int &r){
    //if l,r lies outside of lo,hi then return INT_MAX;
    if(r < lo or l > hi){
        return 0;
    }
    // if lo, hi lies completely inside l,r then return the value at index
    if(lo >= l and hi <= r) return segment_tree[i];


    int mid = lo + (hi - lo )/2;
    
    //else call left right
    int left_min = get_sum(2*i+1, lo, mid, l, r);
    int right_min = get_sum(2*i+2, mid+1, hi, l, r);
    return (left_min + right_min);

}

void solve(){
    int n;
    cin>>n;
    int q;
    cin>>q;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    segment_tree.resize(4 * n);

    build_segment_tree(0, 0, n-1, input);

    while(q--){
        int type;
        cin>>type;
        
        if(type == 1){
            int k,u;
            cin>>k>>u;
            k--;
            update(k, 0, 0, n-1, u);
        }
        else{
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            cout<<get_sum(0, 0, n-1, l, r)<<endl;
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

