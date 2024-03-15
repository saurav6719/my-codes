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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >,
             rb_tree_tag, tree_order_statistics_node_update>
    ordered_map;
/* write core logic here */
void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> input(n);
    for(int i =  0; i<n; i++){
        cin>>input[i];
    }
    ordered_map st;
    for(int i = 0; i<k; i++){
        st[input[i]]++;
    } 
    int a = 0;
    int b = k-1;
    while(b<n){
        int median;
        if(k&1){
            median = *(st.find_by_order(k/2));
        }
        else{
            median = *(st.find_by_order((k/2) - 1));
        }
        cout<<median<<" ";
        // debug(input[a]);
        a++;
        b++;
        st[input[a]]++;
        st[input[b]]++;
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

