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
//link -> https://leetcode.com/problems/knight-probability-in-chessboard/description/
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    class Solution {
public:
double dp[30][30][105];
double f(int i, int j, int k, int n){
    //base case
    if(i<0 or j<0 or i>=n or j>=n) return 0;
    if(k==0) return 1;
    if(dp[i][j][k]>-0.9) return dp[i][j][k];
    return dp[i][j][k] = (f(i+1,j+2,k-1,n)/8 + f(i+1,j-2,k-1,n)/8+ f(i-1,j+2,k-1,n)/8 + f(i-1,j-2,k-1,n)/8 +f(i+2,j+1,k-1,n)/8 + f(i+2,j-1,k-1,n)/8 +f(i-2,j+1,k-1,n)/8 + f(i-2,j-1,k-1,n)/8 );
}
    double knightProbability(int n, int k, int row, int column) {
        memset(dp,-1,sizeof dp);
        return f(row,column,k,n);

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