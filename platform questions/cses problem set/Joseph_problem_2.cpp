#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#else
#define debug(x)
#endif
#define endl "\n"
#define int long long int

#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;
using namespace __gnu_pbds; 
template<typename T>
#define ordered_set_type tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>


#define mod 1000000007
void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    ordered_set_type now;
    for(int i = 1; i<=n; i++){
        now.insert(i);
    }
    int start = 0;
    while(now.size() > 0){
        start %= now.size();
        int rem = (start + k) % now.size();
        start = rem;
        auto t = now.find_by_order(rem);
        cout<<*t<<" ";
        now.erase(t);
    } 
}
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
        solve<int>();
    }
return 0;
}
