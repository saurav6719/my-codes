/**
 *    author: Saurav
 *    created: 2025.01.02 02:35:59
 **/

/* includes and all */

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  // For ordered set (tree)
#include <ext/pb_ds/tree_policy.hpp>     // For tree policies
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
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


/* write core logic here */
int count_in_range(ordered_set& o_set, int l, int r) {
    // Use lower_bound and upper_bound to find the range
    return o_set.order_of_key(r + 1) - o_set.order_of_key(l);
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(auto &x : v){
        cin>>x;
    }

    map<int,vector<int> > queryend;
    vector<pp> queries(q);
    for(int i = 0; i<q; i++){
        int l,r;
        cin>>l>>r;
        l--,r--;
        queries[i] = make_pair(l,r);
        queryend[r].emplace_back(i);
    }

    map<int,int> mp;
    ordered_set currele;
    vector<int> ans(q);

    for(int i = 0; i<n; i++){
        int curr = v[i];
        if(mp.find(curr) != mp.end()){
            currele.erase(mp[curr]);
            currele.insert(i);
            mp[curr] = i;
        }
        else{
            currele.insert(i);
            mp[curr] = i;
        }
        for(auto ele : queryend[i]){
            int l = queries[ele].first;
            int r = queries[ele].second;
            ans[ele] = count_in_range(currele,l,r);
        }
    }

    for(auto x : ans){
        cout<<x<<endl;
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

