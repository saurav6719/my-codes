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
void helper(vector<int>&nums, vector<vector<int> >&ans,int i, vector<int> sub){
    if(i==nums.size()){
        ans.push_back(sub);
        return;
    }
    helper(nums,ans,i+1,sub);
    sub.push_back(nums[i]);
    helper(nums,ans,i+1,sub);
    return;
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> result;
        helper(nums,ans,0,result);
        return ans;
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