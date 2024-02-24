#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<set>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#else
#define debug(x)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;
void solve(){
    int x;
    cin>>x;
    int n;
    cin>>n;
    multiset<int> st;
    set<int> s;
    st.insert(x);
    s.insert(0);
    s.insert(x);
    for(int i = 1; i<=n; i++){
        int ele ;
        cin>>ele;
        s.insert(ele);
        auto it = s.find(ele);
        int left = *prev(it);
        int right = *next(it);
        auto er = st.find(right - left);
        st.erase(er);
        st.insert(ele-left);
        st.insert(right-ele);
        cout<<*(st.rbegin())<<" ";
    }
    

}
int32_t main(){
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