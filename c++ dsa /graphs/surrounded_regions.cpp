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
void solve(){
    class Solution {
public:
vector<vector<int> > dir ={{0,1},{1,0},{0,-1},{-1,0}};
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int> > visited(row, vector<int> (col,-1));
        queue<pair<int,int>> qu;
        for(int i = 0; i<row;i++){
            if(board[i][0] == 'O'){
                qu.push({i,0});
                visited[i][0] = 1;
            }
            if(board[i][col-1] == 'O'){
                qu.push({i,col-1});
                visited[i][col-1] = 1;
            }
        }
        for(int j = 1; j<col-1;j++){
            if(board[0][j] == 'O'){
                qu.push({0,j});
                visited[0][j] = 1;
            }
            if(board[row-1][j] == 'O'){
                qu.push({row-1,j});
                visited[row-1][j] = 1;
            }
        }
        while(not qu.empty()){
            auto cell = qu.front();
            qu.pop();

            int i = cell.first;
            int j = cell.second;
            visited[i][j] = 1;
            for(int d = 0; d<4;d++){
                int nr = i + dir[d][0];
                int nc = j + dir[d][1];
                if(nr <0 or nc<0 or nr>=row or nc >= col) continue;
                if(visited[nr][nc] == 1) continue;
                if(board[nr][nc] == 'X') continue;
                qu.push({nr,nc});
            }
        }
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(board[i][j] == 'X') continue;
                if(visited[i][j] == 1) continue;
                board[i][j] = 'X';
            }
        }
        return;
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