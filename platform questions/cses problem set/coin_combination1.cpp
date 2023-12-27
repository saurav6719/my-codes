#include<iostream>
#include<vector>
#include<climits>
#define mod 1000000007
using namespace std;
vector<int> dp;
int  f(int n, int x,vector<int> &nums){
    //base case
    dp[0] = 1;
    for(int i = 1; i<=x; i++){
        for(int j = 0; j<n ; j++){
            if(i-nums[j] < 0) continue; 
            dp[i] = ((dp[i] % mod) + (dp[i - nums[j]] % mod) % mod);
        }
    }
    return dp[x];
}
int main(){
    int n;
    cin>>n;
    int x; 
    cin>>x;
    vector<int> nums(n);
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }
    dp.clear();
    dp.resize(1000006,0);
    f(n,x,nums);
    cout<<dp[x] % mod;
}