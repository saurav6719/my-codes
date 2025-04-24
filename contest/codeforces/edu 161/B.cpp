#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
void solve(){//ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> input(n);
    unordered_map<int,int> mp;
    for(int i = 0; i<n; i++){
        int a;
        cin>>a;
        mp[a]++;
        input[i] = a;
    }

    int ans = 0;
    int less = 0;
    for(int i = 0; i<=n;i++){
        //equilateral
        ans += (mp[i] * (mp[i]-1) * (mp[i]-2) )/6;
        //isosceles
        ans += (mp[i] * (mp[i]-1) )/2 * less;
        less += mp[i];
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