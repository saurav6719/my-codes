#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

int countWaysToMakeRegular(const string& s, int k) {
    int n = s.length();
    vector<vector<int>> dp(k + 1, vector<int>(2 * n + 1, 0));
    
    dp[0][n] = 1;  // Initial state with 0 flips and balance 0 (shifted by n to avoid negative indices)
    
    for (int i = 0; i < n; ++i) {
        vector<vector<int>> new_dp(k + 1, vector<int>(2 * n + 1, 0));
        
        for (int j = 0; j <= k; ++j) {
            for (int b = 0; b <= 2 * n; ++b) {
                if (dp[j][b] == 0) continue;
                
                if (s[i] == '(') {
                    // If we leave it as '('
                    if (b + 1 <= 2 * n) {
                        new_dp[j][b + 1] = (new_dp[j][b + 1] + dp[j][b]) % MOD;
                    }
                    // If we flip it to ')'
                    if (j + 1 <= k && b - 1 >= 0) {
                        new_dp[j + 1][b - 1] = (new_dp[j + 1][b - 1] + dp[j][b]) % MOD;
                    }
                } else { // s[i] == ')'
                    // If we leave it as ')'
                    if (b - 1 >= 0) {
                        new_dp[j][b - 1] = (new_dp[j][b - 1] + dp[j][b]) % MOD;
                    }
                    // If we flip it to '('
                    if (j + 1 <= k && b + 1 <= 2 * n) {
                        new_dp[j + 1][b + 1] = (new_dp[j + 1][b + 1] + dp[j][b]) % MOD;
                    }
                }
            }
        }
        
        dp = new_dp;
    }
    
    // The result is the sum of all ways to have balance 0 (shifted back by n) with up to k flips
    return dp[k][n];
}

int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    string s;
    cin>>s;
    
    
    int result = countWaysToMakeRegular(s, k);
    cout << result << endl;
    
    return 0;
}
