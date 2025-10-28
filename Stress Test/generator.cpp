/**
 *    author: Saurav
 *    created: 2025.10.14
 *    Random input generator
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(0));

    int T = 1; // number of test cases (you can make this random if needed)
    // cout << T << "\n";

    while (T--) {
        int n = 100000; // 1 <= n <= 100000
        int q = 100000; // 1 <= q <= 100000
        cout << n << "\n";

        // Generate array
        for (int i = 0; i < n; i++) {
            int val = 1000000000; // 1 <= a[i] <= 1000000000
            cout << val << (i + 1 == n ? '\n' : ' ');
        }

        cout << q << "\n";

        // Generate queries
        for (int i = 0; i < q; i++) {
            int l = rand() % n + 1;
            int r = rand() % n + 1;
            if (l > r) swap(l, r);
            cout << l << " " << r << "\n";
        }
    }
}
