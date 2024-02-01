#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
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
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<n; i++){
        cin>>b[i];
    }
    vector<int> index(n+5,-1);
    for(int i = 0; i<n; i++){
        int ele = a[i];
        index[ele] = i;
    }
    for(int i = 0; i<n; i++){
        debug(a[i]);
        if(a[i] == i+1) continue;
        int idx = index[i+1];
        debug(idx);
        swap(a[i], a[idx]);
        swap(index[a[i]], index[a[idx]]);
        swap(b[i], b[idx]);
    }

    for(int i = 0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i<n; i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;



}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}