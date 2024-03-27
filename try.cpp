#include<bits/stdc++.h>
#define mod 1000000007
#define int long long int
using namespace std;
vector<vector<int> > dp;

int  f(int n, int x,vector<int> &nums, int i){
    //base case
	
	if(i>=n) return 0;
	if(x==0) return 1;
	if(x<0) return 0;
    if(dp[x][i] != -1) return dp[x][i];
    int sum = 0;
	sum = ((sum % mod ) + (f(n,x-nums[i], nums, i) % mod) % mod);
	sum = ((sum % mod ) + (f(n,x, nums, i+1) % mod) % mod);
    return dp[x][i] = sum;
}
signed main(){
    int n;
    cin>>n;
    int x; 
    cin>>x;
    vector<int> nums(n);
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }
    dp.clear();
    dp.resize(x+5,vector<int> (n+5, -1));
    cout<<f(n,x,nums, 0) % mod;
    //cout<<dp[x][0] % mod;
}
