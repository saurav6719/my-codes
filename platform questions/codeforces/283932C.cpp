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
bool poss(int mid,int x, int y,int n){
    if(mid < min(x,y)) return false;
    int sum = 1;
    int mid_copy = mid;
    mid_copy -= min(x,y);
    sum += mid_copy/ x;
    sum += mid_copy/ y;
    if(sum >= n) return true;
    return false;
}
void solve(){

    int n,x,y;
    cin>>n>>x>>y;
    int lo = 0;
    int hi = n * min(x,y);
    int result = -1;
    while(lo <= hi ){
        int mid = lo +(hi-lo)/2;
        if(poss(mid,x,y,n)) {
            result = mid;
            hi = mid -1;
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