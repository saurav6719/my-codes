#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
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
//link -> https://leetcode.com/problems/largest-divisible-subset/?envType=daily-question&envId=2024-02-09
void solve(){
    class Solution {
public:


    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n+1,0);
        int mx = 1;
        dp[0] = 1;
        for(int i = 1; i<n; i++){
            for(int j = i-1 ; j>=0 ; j--){
                if(nums[i] % nums[j] == 0){
                    dp[i] = max(dp[j]+1, dp[i]);
                }
            }
            if(dp[i] == 0) dp[i] = 1;
            if(dp[i] > mx) mx = dp[i];
        }
        cout<<mx;
        int idx = -1;
        for(int i = 0; i<n; i++){
            if(dp[i] == mx) {
                idx = i;
                break;
            }
        }
        vector<int> ans;
        ans.push_back(nums[idx]);
        for(int i = idx-1; i>=0; i--){
            if(dp[i] == mx -1) {
                if(ans[ans.size() - 1] % nums[i] == 0){
                    ans.push_back(nums[i]);
                    mx--;
                }
            }
        }
        return ans;
    }
};
}
int32_t main(){
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