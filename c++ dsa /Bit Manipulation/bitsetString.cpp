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
    int n = 8;
    cout<<bitset<8>(n)<<endl;
    cout<<bitset<8>(n).count()<<endl;
    cout<<bitset<8>(n).flip()<<endl;
    cout<<bitset<8>(n).any()<<endl;
    cout<<bitset<8>(n).none()<<endl;
    cout<<bitset<8>(n).all()<<endl;
    string s = bitset<8>(n).to_string();
    cout<<s<<endl;
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