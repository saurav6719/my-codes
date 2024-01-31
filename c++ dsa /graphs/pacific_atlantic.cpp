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
//link -> https://leetcode.com/problems/pacific-atlantic-water-flow/
void solve(){
    class Solution {
public:
int row;
int col;
vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};

void bfs(vector<vector<bool>> &v, vector<vector<int> > &heights, queue<pair<int,int>> &qu){
    while(not qu.empty()){
        auto cell = qu.front();
        qu.pop();
        int i = cell.first;
        int j = cell.second;
        v[i][j] = true;
        for(int d = 0; d<4; d++){
            int newRow = i + dir[d].first;
            int newCol = j+ dir[d].second;
            if(newRow <0 or newCol<0 or newRow >=row or  newCol >=col) continue;
            if(v[newRow][newCol]) continue;
            if(heights[newRow][newCol] < heights[i][j] ) continue;
            qu.push({newRow,newCol});

        }
    }
    return;
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights[0].size();
        queue<pair<int,int>> pacific;
        queue<pair<int,int>> atlantic;
        for(int i = 0 ; i<row; i++){
            pacific.push({i,0});
            atlantic.push({i,col-1});
        }
        for(int j = 1; j<col;j++){
            pacific.push({0,j});
        }

        for(int j = 0; j<col-1;j++){
            atlantic.push({row-1,j});
        }

        vector<vector<bool> > pacifici(row,vector<bool>(col,false));
        vector<vector<bool> > atlantici(row,vector<bool>(col,false));

        bfs(pacifici,heights,pacific);
        bfs(atlantici,heights,atlantic);

        vector<vector<int> >  result;
        for(int i = 0 ; i<row;i++){
            for(int j = 0; j<col; j++){
                if(pacifici[i][j] and atlantici[i][j] ) result.push_back({i,j});
            }

        }
        return result;


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