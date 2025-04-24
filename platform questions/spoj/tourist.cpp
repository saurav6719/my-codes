#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<cstring>
#define endl "\n"
// #define int long long int
#define mod 1000000007
#define ll long long int
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
int n;
int m;
char mat[105][105];
int dp[105][105][105];

ll f(ll i, ll j, ll x, ll y) {

    if(i > n or j > m or x > n or y > m or mat[i][j] == '#' or mat[x][y] == '#') return 0;
    if(i == n and j == m) { 
        return mat[i][j] == '*';
    }
    // no need to check x==n-1 and y==m-1 because if i and j are at bottom right then 
//     // 100 % x and y will also be at bottom right or they are out of map 
    if(dp[i][j][x] != -1) return dp[i][j][x];
    ll result = INT_MIN;

    result = max(result, f(i+1, j, x+1, y));
    result = max(result, f(i+1, j, x, y+1));
    result = max(result, f(i, j+1, x+1, y));
    result = max(result, f(i, j+1, x, y+1));

    result += (mat[i][j] == '*');
    result += (mat[x][y] == '*');

    // remove repition
    if(i == x and j == y and mat[i][j] == '*') result--;

    return dp[i][j][x] = result;

}
// int f(int i,int j,int x,int y){
//     //base case
//     if(i>n or j>m or  x>n or y>m or map[i][j] == '#' or map[x][y] == '#') return 0;
//     if(i==n or j==m){ 
//         return (map[i][j] == '*');
//     }
//     // no need to check x==n-1 and y==m-1 because if i and j are at bottom right then 
//     // 100 % x and y will also be at bottom right or they are out of map 
//     if(dp[i][j][x] != -1) return dp[i][j][x];
//     int result = INT_MIN;
//     result = max(result , f(i+1,j,x+1,y));
//     result = max(result , f(i+1,j,x,y+1));
//     result = max(result , f(i,j+1,x+1,y));
//     result = max(result , f(i,j+1,x,y+1));
    
//     result += (map[i][j] == '*');
//     result += (map[x][y] == '*');
//     //avoid repition
//     if(i==x and j==y and map[i][j] == '*') result--;
    
//     return dp[i][j][x] = result;
// }
int32_t main(){
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        cin>>m;
        cin>>n;
        memset(dp,-1,sizeof dp);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin>>mat[i][j];
            }
        }
        cout<<f(1,1,1,1)<<endl;
    }
return 0;
}