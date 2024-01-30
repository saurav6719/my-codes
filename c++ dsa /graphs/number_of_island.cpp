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
//link -> https://leetcode.com/problems/number-of-islands/
void solve(){
    class Solution {
public:
void dfs(vector<vector<char>> & grid , int r, int c){
    int row = grid.size();
    int col = grid[0].size();
    grid[r][c] = '0';
    // up
    if(r>=1 and grid[r-1][c] == '1') dfs(grid,r-1,c);
    // down
    if(r<row-1 and grid[r+1][c] == '1' ) dfs(grid,r+1,c);
    // left
    if(c>=1 and grid[r][c-1] == '1') dfs(grid,r,c-1);
    // right
    if(c<col-1 and grid[r][c+1] == '1') dfs(grid,r,c+1);
}
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for(int r = 0; r<row; r++){
            for(int c = 0; c<col;c++){
                if(grid[r][c] == '0') continue;
                dfs(grid , r ,c);
                ans++; 
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