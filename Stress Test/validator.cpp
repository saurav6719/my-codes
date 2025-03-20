#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // if (!(cin >> T) || T <= 0) {
    //     cerr << "Error: Invalid number of test cases T.\n";
    //     return 1;
    // }

    while (T--) {
        int n, q;
        if (!(cin >> n) || n <= 0) {
            cerr << "Error: Invalid n (array size).\n";
            return 1;
        }

        if (!(cin >> q) || q < 0) {
            // if there is no query just comment this part
            cerr << "Error: Invalid number of queries q.\n";
            return 1;
        }

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            if (!(cin >> arr[i]) || arr[i] < -1e9 || arr[i] > 1e9){
                // manually update contrainst as per the question
                cerr << "Error: Array value out of bounds (1 ≤ ai ≤ 1e9).\n";
                return 1;
            }
        }

        q = 0;

        for (int i = 0; i < q; i++){
            // if there is no query just comment this part
            int idx, x;
            if (!(cin >> idx >> x) || idx < 1 || idx > n || x < -1e9 || x > 1e9) {
                cerr << "Error: Invalid query (1 ≤ l ≤ r ≤ n, -1e9 ≤ x ≤ 1e9).\n";
                return 1;
            }
        }
    }
    return 0;
}
