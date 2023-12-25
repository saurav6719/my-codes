#include <iostream>
#include<vector>
using namespace std;
vector<int> dp;
int minStep(int n)
{
    // base case
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (n == 3)
        return 1;

    if(dp[n] != -1){
        return dp[n];
    }

    return dp[n] = 1  + min(minStep(n - 1), min(((n % 2 == 0) ? minStep(n / 2) : INT_MAX), ((n % 3 == 0) ? minStep(n / 3) : INT_MAX)));
}
int main()
{   int n;
    cin>>n;

    dp.clear();
    dp.resize(n+5,-1);
    cout << minStep(n);
    return 0;
}