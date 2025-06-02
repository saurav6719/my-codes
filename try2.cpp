#include <bits/stdc++.h>
using namespace std;

// Global variables (for simplicity):
long long A, X, Y;
unordered_map<long long, long double> dp;

// f(n) = minimum expected cost to reduce n → 0
long double f(long long n) {
    if (n == 0) return 0.0L;
    if (dp.count(n)) return dp[n];

    // 1) Option 1: pay X to do n <- floor(n/A)
    long double best = f(n / A) + (long double)X;

    // 2) Option 2: roll a dice, cost = E
    //    Solve: f(n) = Y + (1/6)*[ f(n) + sum_{b=2..6} f(n/b) ]
    //    ⇒ 5/6 f(n) = Y + (1/6)*sum_{b=2..6} f(n/b)
    //    ⇒ f(n) = (6·Y + sum_{b=2..6} f(n/b)) / 5
    long double sum_sub = 0.0L;
    for (int b = 2; b <= 6; ++b) {
        sum_sub += f(n / b);
    }
    long double cost_roll = (6.0L * (long double)Y + sum_sub) / 5.0L;

    best = min(best, cost_roll);
    return dp[n] = best;
}

int main() {
    long long N;
    cin >> N >> A >> X >> Y;
    // Make sure to clear dp if needed
    long double ans = f(N);
    cout << fixed << setprecision(10) << ans;
    return 0;
}
