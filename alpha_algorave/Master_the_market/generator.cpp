#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(0));

    int n = rand() % 100 + 1; // 1 ≤ n ≤ 100
    int q = rand() % 100 + 1; // 1 ≤ q ≤ 100
    cout << n << " " << q << "\n";

    // Initial stock prices
    for (int i = 1; i <= n; i++) {
        cout << (rand() % 1000000000 + 1) << (i == n ? '\n' : ' ');
    }

    // q updates (i, x)
    for (int j = 0; j < q; j++) {
        int i = rand() % n + 1; // 1 ≤ i ≤ n
        int x = rand() % 1000000000 + 1; // 1 ≤ x ≤ 1e9
        cout << i << " " << x << "\n";
    }

    return 0;
}
