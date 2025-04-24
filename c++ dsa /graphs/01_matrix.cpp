#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<queue>
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
//link -> https://leetcode.com/problems/01-matrix/
void solve(){
    class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int> > ans(row, vector<int> (col,-1));
        queue<pair<int,int>> qu;

        for(int i = 0; i<row;i++){
            for(int j = 0; j<col;j++){
                if(mat[i][j] == 0){
                    qu.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }

        vector<vector<int>> dir= {{1,0}, {0,1}, {0,-1}, {-1,0}};

        while(not qu.empty()){
            auto cell = qu.front();
            qu.pop();
            int i = cell.first;
            int j = cell.second;
            for(int d= 0;d<4;d++){
                int nr = i + dir[d][0];
                int nc = j + dir[d][1];
                if(nr <0 or nc<0 or nr>=row or nc>= col) continue;
                if(ans[nr][nc] != -1) continue;
                ans[nr][nc] = ans[i][j] + 1;
                qu.push({nr,nc});

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