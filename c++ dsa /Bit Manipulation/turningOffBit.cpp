#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<bitset>
#include<algorithm>
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;


void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n = 35;
    cout<<bitset<32>(n) <<endl;  /// 00100011
    int k = 5;
    n = n | (1<<k);  //now kth bit is set 00100011
    n = n ^ (1<<k); // now kth bit is unset
    cout<<bitset<32>(n) <<endl;
}


int32_t main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}