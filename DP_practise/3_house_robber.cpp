// #include<bits/stdc++.h>
// #ifndef ONLINE_JUDGE
// #define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
// #else
// #define debug(x)
// #endif
// #define endl "\n"
// #define int long long int
// #define mod 1000000007
// #define mn(a,b,c) min(a,min(b,c))
// #define mx(a,b,c) max(a,max(b,c))
// using namespace std;
// //link -> https://leetcode.com/problems/house-robber/
// void solve(){
//     class Solution {
// public:
// vector<int> dp;
// int f(vector<int> &nums, int i){
//     //base case 
//     int n = nums.size();
//     if(i==n-2) return dp[i] = max(nums[n-2], nums[n-1]);
//     if(i==n-1) return dp[i] = nums[i];
//     if(dp[i] != -1) return dp[i];
    
//     return dp[i] = max(f(nums,i+1) , nums[i]+f(nums,i+2));

// }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         dp.resize(n+5,-1);
//         return f(nums,0);
//     }
// };
// }
// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     #ifndef ONLINE_JUDGE
//         freopen("Error.txt" , "w" , stderr);
//     #endif
//     int t;
//     //cin>>t;
//     t = 1;
//     while(t--){
//         solve();
//     }
// return 0;
// }

#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#else
#define debug(x)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;
//link -> https://leetcode.com/problems/house-robber/
void solve(){
    class Solution {
public:
vector<int> dp;
int f(vector<int> &nums){
    int n = nums.size();
    if(n>=2) dp[n-2] = max(nums[n-2], nums[n-1]);
    if(n>=1) dp[n-1] = nums[n-1];
    if(n>=3){
        for(int j = n-3; j>=0; j--){
        dp[j] = max(nums[j] + dp[j+2] , dp[j+1]);
    }
    }
    return dp[0];
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.clear();
        dp.resize(n+5);
        return f(nums);
    }
};
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}