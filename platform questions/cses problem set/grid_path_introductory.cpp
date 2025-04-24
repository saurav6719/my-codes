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
const int n = 7;
const int total_steps = 48;
int reserved[49];
bool visited [n][n];
string path;
void move(int row, int col, int &ans , int &steps){
    if(row == n-1 and col == 0){
        if(steps == total_steps) ans++;
        return;
    }
    // wall or left right unvisited up down visited
    if (((row + 1 == n || (visited[row - 1][col] && visited[row + 1][col])) && col - 1 >= 0 && col + 1 < n && !visited[row][col - 1] && !visited[row][col + 1])){
        return ;
    }
    if(((col + 1 == n || (visited[row][col - 1] && visited[row][col + 1])) && row - 1 >= 0 && row + 1 < n && !visited[row - 1][col] && !visited[row + 1][col])){
        return ;
    }
    if(((row == 0 || (visited[row + 1][col] && visited[row - 1][col])) && col - 1 >= 0 && col + 1 < n && !visited[row][col - 1] && !visited[row][col + 1])){
        return ;
    }
    if(((col == 0 || (visited[row][col + 1] && visited[row][col - 1])) && row - 1 >= 0 && row + 1 < n && !visited[row - 1][col] && !visited[row + 1][col])){
        return;
    }

    visited[row][col] = true;
    if(path[steps] != '?'){
        if(path[steps] == 'U'){
            if(row - 1>= 0){
                if(!visited[row-1][col]){
                    steps++;
                    move(row-1,col,ans,steps);
                    steps--;
                }
            }
        }
        else if(path[steps] == 'R'){
            if(col + 1 < n){
                if(!visited[row][col+1]){
                    steps++;
                    move(row,col+1,ans,steps);
                    steps--;
                }
            }
        }
        else if(path[steps] == 'D'){
            if(row + 1 < n){
                if(!visited[row+1][col]){
                    steps++;
                    move(row+1,col,ans,steps);
                    steps--;
                }
            }
        }
        else if(path[steps] == 'L'){
            if(col - 1>= 0){
                if(!visited[row][col-1]){
                    steps++;
                    move(row,col-1,ans,steps);
                    steps--;
                }
            }
        }
    }
    else{
        // move down
        if (row + 1 < n){
            if (!visited[row + 1][col])
            {
                steps++;
                move(row + 1, col, ans, steps);
                steps--;
            }
        }
        // move right
        if (col + 1 < n){
            if (!visited[row][col + 1])
            {
                steps++;
                move(row, col + 1, ans, steps);
                steps--;
            }
        }
        // move up
        if (row - 1 >= 0){
            if (!visited[row - 1][col])
            {
                steps++;
                move(row - 1, col, ans, steps);
                steps--;
            }
        }
        // move left
        if (col - 1 >= 0)
        {
            if (!visited[row][col - 1])
            {
                steps++;
                move(row, col - 1, ans, steps);
                steps--;
            }
        }
    }
    visited[row][col] = false;
}
void solve(){
    cin>>path;
    for(int i = 0; i<path.length(); i++){
        if(path[i] == '?') reserved[i] = -1;
        else if(path[i] == 'U') reserved[i] = 0;
        else if(path[i] == 'R') reserved[i] = 1;
        else if(path[i] == 'D') reserved[i] = 2;
        else if(path[i] == 'L') reserved[i] = 3;
    }
    int ans = 0;
    int steps = 0;
    move(0,0,ans,steps);
    cout<<ans<<endl;

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