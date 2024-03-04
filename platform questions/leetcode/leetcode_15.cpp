/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Saurav     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \___/   /
           \  -----  /
             \_____/
  
  Happy coding! 
*/

/* includes and all */

#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

//link -> https://leetcode.com/problems/3sum/

/* write core logic here */
void solve(){
    class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        set<vector<int> > st;
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(i>0 and nums[i] == nums[i-1]) continue;
            int l = i+1;
            int r = n-1;
            while(l<r){
                int target = 0 - nums[i];
                if(nums[l] + nums[r] == target){
                    if(i!=l and i!= r){
                        vector<int> ans;
                        ans.push_back(nums[i]);
                        ans.push_back(nums[l]);
                        ans.push_back(nums[r]);
                        sort(ans.begin(), ans.end());
                        
                        if(st.count(ans) == 0)res.push_back(ans);
                        st.insert(ans);
                       
                    }
                    l++;
                }
                else if(nums[l] + nums[r] < target){
                    l++;
                }
                else r--;
            }
        }
        return res;
    }
};
}
/* logic ends */

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

