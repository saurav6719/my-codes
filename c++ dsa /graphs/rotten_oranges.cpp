#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
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
//link -> https://leetcode.com/problems/rotting-oranges/
void solve(){
    class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> qu;
        int fo = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] ==1) fo++;
                else if (grid[i][j] == 2) qu.push({i,j});
            }

        }
        qu.push({-1,-1});
        int mins = 0;
        vector<vector<int> > dir={{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(not qu.empty()){
            auto cell = qu.front();
            int i = cell.first;
            int j = cell.second;
            qu.pop();
            if(cell.first == -1 and cell.second == -1){
                mins++;
                if(not qu.empty()){
                    qu.push({i,j});
                }
                else break;
            }
            else{
                int i = cell.first;
                int j = cell.second;
                for(int d = 0; d<4;d++){
                    int nr = i + dir[d][0];
                    int nc = j + dir[d][1];
                    if(nr<0 or nc<0 or nr>=n or nc >= m) continue;
                    if(grid[nr][nc] == 2 or grid[nr][nc] == 0) continue;
                    fo--;
                    grid[nr][nc] = 2;
                    qu.push({nr,nc});
                }
            }
            
        }
        return (fo==0)? mins-1:-1;
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