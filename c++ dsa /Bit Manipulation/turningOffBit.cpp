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

string binary(int n){
    bitset<8> b(n);
    return b.to_string();
}

void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n = 35;
    cout<<binary(n)<<endl;;
    for(int i = 0; i<8; i++){
        if(n & (1<<i)) {  // bit is set
            n = n ^ (1<<i);
        }
    }
    cout<<"now all the bits are unset "<<endl<<binary(n);
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