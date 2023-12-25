#include <iostream>
#include <vector>
#include <climits>
#include <cmath> // Include cmath for abs
using namespace std;
vector<int> heights;
vector<int> dp;
int k;
int f(int x) {
    dp[heights.size() - 1] = 0;
    for(int i = heights.size()-2; i>=0; i--){
        dp[i] = INT_MAX;
        for(int j = 1; j<=k ; j++){
            if(i+j >= heights.size()) break;
            dp[i] = min(dp[i] , (abs(heights[i] - heights[i+j]) + dp[i+j]));
        }
    }
    return dp[x];
}
int main() {
    int n;
    cin >> n;
    dp.resize(n);
    dp.clear();
    heights.resize(n , INT_MAX);
    cin >> k;
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    cout << f(0);
    return 0;
}
