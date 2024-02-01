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
string getbinary(int x){
    bitset<32> b(x);
    return b.to_string();
}
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    cout<<getbinary(256)<<endl;
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