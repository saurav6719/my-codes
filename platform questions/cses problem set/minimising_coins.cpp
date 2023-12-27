#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> dp;
int minimum_coins(int n, int x, vector<int> &nums){
    //base case
    
    if(dp[x] != -1) return dp[x];
    int result = INT_MAX - 100;
    
    return dp[x]= 1 + result;
}
int main(){
    int n;
    cin>>n;
    int x; 
    cin>>x;
    vector<int> nums;
    for(int i = 0; i<n; i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    vector<int> dp;
    dp.clear();
    dp.resize(1000006,INT_MAX - 100);
    dp[0] = 0;
    for(int i = 1; i<= x; i++){
        for(int j = 0; j<n ; j++){
            if( i - nums[j] < 0 ) continue;
            dp[i] = min(dp[i] , 1 + (dp[i - nums[j]]));
    }
    }
    if(dp[x] > INT_MAX - 1000 ) cout<<-1;
    else cout<<dp[x];
    return 0;
}