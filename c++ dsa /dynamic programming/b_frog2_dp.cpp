#include <iostream>
#include <vector>
#include <climits>
#include <cmath> // Include cmath for abs
using namespace std;
vector<int> heights;
vector<int> dp;
int k;
int f(int i) {
    // base case
    if (i == heights.size() -1 ) return 0; // last stone, no cost
    // optimization
    if (dp[i] != -1) return dp[i];
    int ans = INT_MAX;
    // recurrence relation
    for (int j = 1; j <= k ; j++) {
        if(i+j >= heights.size()) break;
        int cost = abs(heights[i] - heights[i + j]) + f(i + j);
        ans = min(ans, cost);
    }
    dp[i] = ans;
    return ans;
}
int main() {
    int n;
    cin >> n;
    heights.resize(n);
    dp.resize(n, -1);
    cin >> k;
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    cout << f(0);
    return 0;
}
