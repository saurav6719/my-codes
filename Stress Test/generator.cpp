#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0)); // Seed for random number generator

    int N = 10;
    int K = rand() % (N - 1) + 1; // 1 ≤ K < N

    // Print N and K
    cout << N << " " << K << endl;

    // Generate N integers C1 to CN (1 ≤ Ci ≤ 20)
    for (int i = 0; i < N; ++i) {
        cout << (rand() % 20 + 1) << " ";
    }
    cout << endl;

    // Generate binary string of length K
    for (int i = 0; i < K; ++i) {
        cout << (rand() % 2);
    }

    return 0;
}
