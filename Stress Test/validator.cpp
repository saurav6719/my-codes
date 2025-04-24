#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    if (!(cin >> T) || T <= 0) {
        cerr << "Error: Invalid number of test cases T.\n";
        return 1;
    }

    while (T--) {
        int N, K;
        if (!(cin >> N >> K) || N <= 0 || K < 0) {
            cerr << "Error: Invalid values of N or K (N > 0, K ≥ 0).\n";
            return 1;
        }

        while(N--) {
            int x;
            if (!(cin >> x) || x < 0 || x > 1e9) {
                cerr << "Error: Invalid value in the array (0 ≤ x ≤ 1e9).\n";
                return 1;
            }
        }
    }

    return 0;
}
