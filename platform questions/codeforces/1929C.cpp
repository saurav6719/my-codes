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
    int k, x,a;
    cin>>k>>x>>a;
    int used = 1;
    int _a = a;
    _a--;
    //debug(_a);
    int bet = (used / (k-1))+1; 
    //debug(bet);
    for(int i = 2; i<=x;i++){
        bet = (used / (k-1))+1;
        used += bet;
        _a-=bet;
        if(_a < 0){
            cout<<"NO"<<endl;
            return;
        }
        // debug(used);
        // debug(bet);
        // debug(_a);
    }
    bet = (used / (k-1))+1;
    if(bet > _a) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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