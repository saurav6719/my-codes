#include<iostream>
#include<vector>
using namespace std;
bool isSafe(vector<vector<int> > &grid, int i, int j, int n){
    return i>=0 and j>=0 and i<n and j<n and (grid[i][j] == -1);
}
void display(vector<vector<int> > & grid, int n){
   
    for(int i = 0; i<n ; i++){
        for(int j = 0; j< n ; j++){
            cout<<grid[i][j]<<"     ";
        }
        cout<<endl<<endl;
    }

    cout<<"***************"<<endl<<endl<<endl;
    
}

void f(vector<vector<int> > &grid, int i, int j, int n, int count){
    // base case 
    if(count == n*n) {
        grid[i][j] = count;
        
        display(grid, n);
    
        grid[i][j] = -1; // backtrack
    }
    grid[i][j] = count;
    if(isSafe(grid,i+2,j+1,n)) f(grid,i+2,j+1,n,count+1);
    if(isSafe(grid,i+2,j-1,n)) f(grid,i+2,j-1,n,count+1);
    if(isSafe(grid,i+1,j+2,n)) f(grid,i+1,j+2,n,count+1);
    if(isSafe(grid,i+1,j-2,n)) f(grid,i+1,j-2,n,count+1);
    if(isSafe(grid,i-2,j+1,n)) f(grid,i-2,j+1,n,count+1);
    if(isSafe(grid,i-2,j-1,n)) f(grid,i-2,j-1,n,count+1);
    if(isSafe(grid,i-1,j+2,n)) f(grid,i-1,j+2,n,count+1);
    if(isSafe(grid,i-1,j-2,n)) f(grid,i-1,j-2,n,count+1);
    grid[i][j] = -1;  // backtrack
}
int main(){
    int n = 8;
    int i, j;
    cin>>i>>j;
    vector<vector<int> > grid(n, vector<int> (n, -1));
    f(grid,i,j,n,1);
    return 0;
}