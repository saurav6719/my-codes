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
//link -> https://leetcode.com/problems/coloring-a-border/
void solve(){
    class Solution {
public:
int m;
int n;
vector<vector<int> > visited;
bool isborder(int i , int j , vector<vector<int> >&grid){
    if(i==0 or j==0 or i==(m-1) or j==(n-1)) return true;
    if(grid[i-1][j] != grid[i][j]) return true;
    if(grid[i][j-1] != grid[i][j]) return true;
    if(grid[i][j+1] != grid[i][j]) return true;
    if(grid[i+1][j] != grid[i][j]) return true;
    return false;
}

void dfs(int i , int j ,vector<vector<int>> & grid,  int color, int original){
    grid[i][j] = color;
    if(not isborder(i,j,grid)) {
        grid[i][j] = original;
    }
    if(i>0 and grid[i-1][j] == original) dfs(i-1,j,grid,color,original);
    if(i<m-1 and grid[i+1][j] == original) dfs(i+1,j,grid,color,original);
    if(j>0 and grid[i][j-1] == original) dfs(i,j-1,grid,color,original);
    if(j<n-1 and grid[i][j+1] == original) dfs(i,j+1,grid,color,original);
    
}

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {

        int original = grid[row][col];
        if(original == color) return grid;
        m = grid.size();
        n = grid[0].size();
        visited.resize(m,vector<int> (n,-1));
        dfs(row,col,grid,color,original);
        return grid;
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