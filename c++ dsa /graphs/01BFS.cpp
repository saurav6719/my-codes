#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<deque>
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
//link -> https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
void solve(){
    class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        int dist[n][m];

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                dist[i][j] = 1e9;
            }
        }
        deque<pair<int,int> > dq;
        dq.push_back({0,0});
        dist[0][0] = 0;
        while(!dq.empty()){
            auto curr = dq.front();
            dq.pop_front();
            int x = curr.first;
            int y = curr.second;
            int dir = grid[x][y];
            for(int i = 0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                int edgewt = 1;
                if(i+1 == dir) edgewt = 0;
                if(nx<n and ny<m and nx>=0 and ny>=0){
                    if(dist[nx][ny] > dist[x][y] + edgewt){
                        dist[nx][ny] = dist[x][y] + edgewt;
                    
                        if(edgewt == 1){
                            dq.push_back({nx,ny});
                        }
                        else {
                            dq.push_front({nx,ny});
                        }
                    }
                }
            }
            
        }
        return dist[n-1][m-1];
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