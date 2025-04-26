#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;

    while (T--) {
        int N;
        if (!(cin >> N) || N <= 0) {
            cerr << "Error: Invalid values of N ";
            return 1;
        }

        while(N--) {
            int x;
            if (!(cin >> x) || x < -2500 || x > 2500) {
                cerr << "Error: Invalid value in the array (0 ≤ x ≤ 1e9).\n";
                return 1;
            }
        }
        
        while(N--) {
            int x;
            if (!(cin >> x) || x < -2500 || x > 2500) {
                cerr << "Error: Invalid value in the array (0 ≤ x ≤ 1e9).\n";
                return 1;
            }
        }
    }
    return 0;
}
