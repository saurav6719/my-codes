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
    int x,n;
    cin>>x>>n;
    int ans = x/n;
    int lo = 1;
    int hi = ans;
    int result;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(x%hi == 0){
            cout<<hi<<endl;
            return;
        }
        if(x%mid==0){
            result = mid;
            lo = mid+1;
        }
        hi--;
    }
    cout<<result<<endl;
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