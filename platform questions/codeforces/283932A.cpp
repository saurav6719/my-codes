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
bool poss(int mid, int w, int h, int n){
    // required space 
    int req = n * h * w;
    int fill = (mid / w) * (mid/h);
    if(fill >= n) return true;
    return false;
}
void solve(){
    int w;
    int h;
    int n;
    cin>>w>>h>>n;
    int lo = 0;
    int hi = max(max(w,h) , n*min(w,h));
    int result = hi;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(poss(mid,w,h,n)) {
            result = mid;
            hi = mid - 1;
        }
        else lo = mid + 1; 
    }
    cout<<result;
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