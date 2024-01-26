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
void solve(){
    class Solution {
public:
int binarySearch(vector<int> &arr, int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
        // If x greater, ignore right half
        if (arr[m] > x)
            l = m + 1;
        // If x is smaller, ignore left half
        else
            r = m - 1;
    }
    // If we reach here, then element was not present
    return -1;
}
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        // make prefix array
        vector<int> prefix(n,0);
        prefix[0] = nums[0];
        for(int i = 1; i<n; i++){
            prefix[i] = nums[i] + prefix[i-1];
        }
        //make suffix array
        vector<int> suffix(n,0);
        suffix[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            suffix[i] = nums[i] + suffix[i+1];
        }


        int result = INT_MAX;

        int i = 0;
        while(i<n){
            //if left right dono se thoda thoda utaye 
            int find = x - prefix[i];
            if(find == 0){
                result = min(result , i+1);
            }
            int index = binarySearch(suffix,0,n-1,find);
            if(index != -1 and index > i){
                result = min(result , (i+1+n-index)); // i+1 elements left se ,, n-index elements right se
            }

            // if bas left se hi uthaye 
            int pre = binarySearch(prefix,0,n-1,x);
            if(pre != -1){
                result = min(result , pre+1); // pre+1 elements left se utha lo
            }

            // if bas right se hi uthaye
            int suf = binarySearch(suffix,0,n-1,x);
            if(suf != -1){
                result = min(result , n-suf); // n-suf element right se utha lo 
            }
            i++;
        }
        if(result == INT_MAX) return -1;
        return result;


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