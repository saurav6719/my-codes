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
    class Solution {
public:
vector<int> dp;
int f(int n){
    int ans = 0;
    if(n==0) return 1;
    if(n==1) return 1;
    if(n==2) return 2;
    if(dp[n] != -1) return dp[n];
    for(int i = 1; i<=n;i++){
        ans+= (f(i-1) * f(n-i));
    }
    return dp[n] = ans;
}
    int numTrees(int n) {
        dp.clear();
        dp.resize(n+5,-1);
        return f(n);
    }
};
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