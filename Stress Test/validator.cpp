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
        if (!(cin >> N >> K) || N <= 0 || K < 2 || K > N) {
            cerr << "Error: Invalid values of N or K (N > 0, K ≥ 0).\n";
            return 1;
        }

        string S;
        if (!(cin >> S) || (int)S.size() != N) {
            cerr << "Error: Invalid string length. Expected length = " << N << ".\n";
            return 1;
        }

        for (char c : S) {
            if (c != 'B' && c != 'G') {
                cerr << "Error: Invalid character in string. Only 'B' or 'G' allowed.\n";
                return 1;
            }
        }
    }

    return 0;
}
