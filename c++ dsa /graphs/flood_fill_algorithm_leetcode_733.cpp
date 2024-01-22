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
//link -> https://leetcode.com/problems/flood-fill/
void solve(){
    class Solution {
public:

int curr ;
bool cango(vector<vector<int>> &grid, int sr, int sc, int color, int i, int j){
    int m = grid.size();
    int n = grid[0].size();
    if(i<0 or i>=m) return false;
    if(j<0 or j>=n) return false;
    if(grid[i][j] != color) return false;
    return true;
}

void  helper(vector<vector<int>>& image, int sr, int sc, int color) {

    if(!cango(image, sr, sc, curr, sr, sc)) {
            return;
    }
    image[sr][sc] = color;
        //check left
        if(cango(image, sr, sc, curr, sr,sc-1)) {
            helper(image,sr,sc-1,color);
        }
        //check right
        if(cango(image, sr, sc, curr, sr,sc+1)) {
            helper(image,sr,sc+1,color);
        }
        //check up
        if(cango(image, sr, sc, curr, sr-1,sc)) {
            helper(image,sr-1,sc,color);
        }
        //check down
        if(cango(image, sr, sc, curr, sr+1,sc)) {
            helper(image,sr+1,sc,color);
        }
}


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        curr = image[sr][sc];
        if (curr != color) {
            helper(image, sr, sc, color);
        }
        return image;
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