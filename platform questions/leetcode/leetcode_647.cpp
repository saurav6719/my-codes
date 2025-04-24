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
//link -> https://leetcode.com/problems/palindromic-substrings/?envType=daily-question&envId=2024-02-10
using namespace std;
void solve(){
    class Solution {
public:

bool isPalindrome (string &s, int i, int j){
    while(i<=j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(isPalindrome(s,i,j)) ans++;
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