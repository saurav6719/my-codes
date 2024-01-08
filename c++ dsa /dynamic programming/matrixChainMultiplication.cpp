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

vector<vector<int> > dp;
int f(int i, int j, vector<int> & arr){
    // base case 
    if(i==j or i+1 == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = __INT_MAX__;
    for(int k = i+1;k<j;k++){
        ans = min(ans, f(i,k,arr) + f(k,j,arr) + arr[i]*arr[j]*arr[k]);
    }
    return dp[i][j] = ans;

}
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }

    dp.clear();
    dp.resize(1005,vector<int> (1005,-1));
    cout<<f(0,n-1,arr);
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