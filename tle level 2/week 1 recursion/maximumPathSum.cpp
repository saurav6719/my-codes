#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int ans = INT_MIN;
void f(vector<vector<int> > &input , int i, int j, int n, int m, int sum){
    // base case 
    if(i==n-1 and j==m-1 ) {
        ans = max(ans,sum);
        return;
    }
    if(i==n-1) f(input,i,j+1,n,m,sum+input[i][j+1]);   // go right
    else if(j==m-1) f(input,i+1,j,n,m,sum+input[i+1][j]);   // go down
    else{
        f(input,i,j+1,n,m,sum+input[i][j+1]); 
        f(input,i+1,j,n,m,sum+input[i+1][j]);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > input(n,vector<int> (m));
    for(int i = 0 ; i<n ; i++){
        for(int j = 0; j<m; j++){
            int a;
            cin>>a;
            input[i][j] = a;
        }
    }
 
    f(input,0,0,n,m,input[0][0]);
 
    cout<<ans;
 
    return 0;
}