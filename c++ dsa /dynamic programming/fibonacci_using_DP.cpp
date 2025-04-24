#include<iostream>
#include<vector>
using namespace std;
vector<int> dp;
int fib(int n ){
    if(n == 0 or n==1 ) return n;
    // dp check
    if(dp[n] != -1) return dp[n];
    dp[n] = fib(n-1) + fib(n-2);
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    dp.clear(); // koi garbage value phle se pdi ho to clear
    dp.resize(n+1 , -1); // fib(n) ke liye n+1 unique subproblems honge 
    cout<<fib(n)<<" ";
}