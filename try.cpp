#include <bits/stdc++.h>
using ll = signed long long int;
#define all(x) (x).begin(), (x).end()
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    int ans = 1, g = __gcd(a[0][0], a[n - 1][m - 1]);
    vector<vector<int>> dp(n, vector<int>(m));

    vector<int> candidates;
    for(int x = 1; x * x <= g; ++x) {
        if(g % x > 0) continue;
        candidates.push_back(x);
        if(x * x < g) candidates.push_back(g / x);
    }

    
        for (int el : candidates) {
            // Reset dp to zeros
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    dp[i][j] = 0;
                }
            }
            dp[0][0] = (a[0][0] % el == 0);

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (a[i][j] % el > 0) continue;
                    if (i > 0) dp[i][j] |= dp[i - 1][j];
                    if (j > 0) dp[i][j] |= dp[i][j - 1];
                }
            }
            if (dp[n - 1][m - 1]) {
                ans = max(ans, el);
            }
        }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}