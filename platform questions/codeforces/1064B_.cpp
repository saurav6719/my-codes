#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include <bitset>
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
void solve(){//ios_base::sync_with_stdio(false);cin.tie(NULL);
    int a;
    cin>>a;
    string s = getbinary(a);
    int count = 0;
    int i = 0;
    while(i<32){
        if(s[i] == '1') count++;
        i++;
    }
    int ans = 1;
    while(count--){
        ans *= 2;
    }
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