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
//link -> https://leetcode.com/problems/generate-parentheses/
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    class Solution {
public:
void f(vector<string> &ans, int n, int open,int close,string &str){
    //base case
    if(open == n ){
        if(close == n){
            ans.push_back(str);
            return;
        }
    }
    if(open > n or close > n ) return;
    if(open>close) {
        str += ')';
        f(ans,n,open,close+1,str);
        str.pop_back();
    }
    str += '(';
    f(ans,n,open+1,close,str);
    str.pop_back();
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        f(ans,n,0,0,str);
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