#include<iostream>
#include<vector>
using namespace std;
vector<int> dp;
int fib(int n ){
    dp.clear(); // koi garbage value phle se pdi ho to clear
    dp.resize(n+1 , -1); // fib(n) ke liye n+1 unique subproblems honge 
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i <= n ; i++){
        dp[i] = dp[i-1] + dp[i-2]; 
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<" ";
}