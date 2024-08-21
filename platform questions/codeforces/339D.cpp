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

//or rep 1 xor rep 2
vector<pp> segment_tree;
void build_segment_tree(int i , int lo, int hi , vector<int> &input){
    if(lo == hi){
        segment_tree[i].first = input[lo];
        segment_tree[i].second = 2;
        return;
    }
    int mid = lo + (hi - lo )/2;

    build_segment_tree(2*i+1, lo , mid, input);
    build_segment_tree(2*i+2, mid+1, hi, input);

    if(segment_tree[2*i+1].second == 1){
        segment_tree[i].first = (segment_tree[2*i+1].first ^ segment_tree[2*i+2].first);
        segment_tree[i].second = 2;
    }
    else{
        segment_tree[i].first = (segment_tree[2*i+1].first | segment_tree[2*i+2].first);
        segment_tree[i].second = 1;
    }
}

void update(int i, int lo , int hi , int idx_to_update , int val_to_update){

    if(lo == hi){
        segment_tree[i].first = val_to_update;
        return;
    }

    int mid = lo + (hi - lo)/2;
    if(idx_to_update <= mid){
        update(2*i+1, lo, mid, idx_to_update, val_to_update);
    }
    else{
        update(2*i+2, mid+1, hi, idx_to_update, val_to_update);
    }

    if(segment_tree[2*i+1].second == 1){
        segment_tree[i].first = (segment_tree[2*i+1].first ^ segment_tree[2*i+2].first);
        segment_tree[i].second = 2;
    }
    else{
        segment_tree[i].first = (segment_tree[2*i+1].first | segment_tree[2*i+2].first);
        segment_tree[i].second = 1;
    }

    
}




void solve(){
    int n;cin>>n;
    int m;cin>>m;
    n = pow(2, n);

    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    segment_tree.resize(4 * n);
    build_segment_tree(0, 0, n-1, input);

    

    while(m--){
        int idx,val;
        cin>>idx>>val;
        idx--;

        update(0, 0, n-1, idx, val);

        cout<<segment_tree[0].first<<endl;
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

