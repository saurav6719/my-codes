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
int f(int k){
    if(k==1) return 0;
    if(k==2) return 6;
    if(k==3) return 28;
    if(k==4) return 96; 
    int ans = 0;
    ans+= ((k*k)*((k*k)-1));
    debug(ans);
    ans -= (4*2);
    debug(ans);
    ans -= (8*3);
    debug(ans);
    ans -= ((k-4)*4*4);
    debug(ans);
    ans -= (4*4);
    debug(ans);
    ans -= (k-4)*4*6;
    debug(ans);
    ans -= (k-4)*(k-4)*8;
    debug(ans);
    ans /= 2;
    return ans;
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1; i<=n;i++){
        cout<<f(i)<<endl;
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