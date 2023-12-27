#include<iostream>
#include<vector>
#include<climits>
#define mx(a,b,c)  max(a,max(b,c))
using namespace std;
vector<vector<int> > dp;
int ans(int n, int a, vector<vector<int> > &input, int act){
    //base case 
    if(dp[n-1][act] != 0)  return dp[n-1][act];
    if(n==1) return mx(input[n-1][0] , input[n-1][1], input[n-1][2]);
    int first = a + max(ans(n-1 , input[n-2][1] , input , 1) , ans(n-1 , input[n-2][2], input, 2));
    int second = a + max(ans(n-1 , input[n-2][0] , input, 0) , ans(n-1 , input[n-2][2], input, 2));
    int third = a + max(ans(n-1 , input[n-2][0] , input, 0) , ans(n-1 , input[n-2][1], input, 1));
    if(act == 0) return dp[n-1][0] = first;
    if(act == 1) return dp[n-1][1] = second;
    return dp[n-1][2] = third;
}
int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n, vector<int> (3,0));
    vector<vector<int> > input(n, vector<int>(3,0));
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<3; j++){
            cin>>input[i][j];
        }
    }
    int x = ans(n,input[n-1][0], input,0 );
    int y = ans(n,input[n-1][1], input,1 );
    int z = ans(n,input[n-1][2], input,2);
    cout<<mx(x,y,z);
}