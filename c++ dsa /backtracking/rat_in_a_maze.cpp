#include<iostream>
#include<vector>
using namespace std;
int ans;
bool cango(int i, int j, int n, vector<vector<int> >&grid){
    
    if(i<0) return false;
    if(j<0) return false;
    if(i>=n) return false;
    if(j>=n) return false;
    if(grid[i][j] != 0) return false;
    return true;
}
void f2(int i, int j, int n, vector<vector<int> > & grid){
    // base case
    if(i == n-1 and j == n-1){
        ans++;
        return;
    }

    grid[i][j] = 2; // visited


    // check left
    if(cango(i,j-1,n,grid)){
        f2(i,j-1,n,grid);
    }  

    // check right
    if(cango(i,j+1,n,grid)){
        f2(i,j+1,n,grid);
    }

    // check up
    if(cango(i-1,j,n,grid)){
        f2(i-1,j,n,grid);
    }

    // check down
    if(cango(i+1,j,n,grid)){
        f2(i+1,j,n,grid);
    }

    grid[i][j] = 0; //backtracking

}
int f(int n ,vector<vector<int> > & grid){
    ans = 0;
    f2(0,0,7,grid);
    return ans;
}
int main(){
    int n = 7;
    
    vector<vector<int> > grid(n,vector<int> (n));
    for(int i = 0; i < n ; i++){
        for(int j = 0; j< n ; j++){
            int a;
            cin>>a;
            grid[i][j] = a;
        }
    }

    cout<<f(n,grid);
    return 0;
}