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
    int n;
    int m;
    cin>>n>>m;
    multiset<int> st;
    for(int i = 0; i<n; i++){
        int ele;
        cin>>ele;
        st.insert(ele);
    }    
    for(int i = 0; i<m; i++){
        int a;
        cin>>a;
        int b = upper_bound(st.begin(), st.end() , a) - st.begin();
        if(b== 0){
            cout<<-1<<endl;
            continue;
        }
        else {
            cout<<endl;

        }

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