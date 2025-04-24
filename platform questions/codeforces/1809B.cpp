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
void solve(){//ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    int ans;
    int x = sqrt(n);
    if(x*x == n) ans = x-1;
    else ans = x;
    cout<<ans<<endl;
}
int32_t main(){
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}