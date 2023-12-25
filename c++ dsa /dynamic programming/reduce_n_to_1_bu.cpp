#include <iostream>
#include<vector>
using namespace std;
vector<int> dp;

int minStep(int n)
{
    dp[0] = INT_MAX;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i <= n ; i++){
        dp[i] = 1  + min(dp[i - 1], min(((i % 2 == 0) ? dp[i/2] : INT_MAX), ((i % 3 == 0) ? dp[i/3] : INT_MAX)));
    }
    return dp[n];
    
}
int main()
{   int n;
    cin>>n;

    dp.clear();
    dp.resize(n+5,-1);
    cout << minStep(n);
    return 0;
}