#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;

void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n = 27;
    cout<<bitset<32> (n)<<endl;
    cout<<"no of leading zeroes are  "<<__builtin_clz(n);
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