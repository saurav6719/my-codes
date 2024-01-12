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
vector<vector<int> > dp;
int f(string &s1, string &s2, int i , int j){
    //base case 
    int n = s1.size();
    int m = s2.size();
    for(int i = 0; i<=n;i++){
        for(int j = 0; j<=m;j++){
            if(i==n) dp[i][j] = m-j;
            if(j==m) dp[i][j] = n-i;
        }
    }
    for(int i = n-1 ;i>=0;i--){
        for(int j = m-1; j>=0; j--){
            if(s1[i] == s2[j])  dp[i][j] = dp[i+1][j+1];
            else dp[i][j] = min({1+dp[i+1][j+1] , 1+dp[i+1][j], 1+dp[i][j+1]});
        }
    }
    return dp[0][0];
}


    int minDistance(string word1, string word2) {
        dp.clear();
        dp.resize(505,vector<int> (505,INT_MAX-1000));
        return f(word1,word2,0,0);
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