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
int ans = 0;
void toh(int left,int middle, int right, int n){
    if(n==0) return;
    ans++;
    toh(left,right,middle,n-1);
    //cout<<left<<" "<<right<<endl;
    toh(middle,left,right,n-1);
}
void tohi(int left,int middle, int right, int n){
    if(n==0) return;
    ans++;
    tohi(left,right,middle,n-1);
    cout<<left<<" "<<right<<endl;
    tohi(middle,left,right,n-1);
}
void solve(){
    int n;
    cin>>n;
    
    toh(1,2,3,n);
    cout<<ans<<endl;
    tohi(1,2,3,n);
    
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