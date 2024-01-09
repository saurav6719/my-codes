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
    int n;
    int k;
    cin>>n>>k;
    int twos = n*2;
    int remain = k - twos;
    int increament = 0;
    while(remain > n){
        increament++;
        remain -= n;
    }
    if(increament < 3 and remain != 0 and increament != 0 ) cout<<"0";
    else cout<<n - remain;
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