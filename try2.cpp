#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to compute binomial coefficient C(n, k)
long long binomialCoeff(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    vector<long long> C(k + 1, 0);
    C[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--) {
            C[j] = C[j] + C[j - 1];
        }
    }
    return C[k];
}

// Function to compute number of valid DFS orders
long long countValidDFSOrders(int n) {
    if (n == 0) return 1;
    if ((n & (n + 1)) != 0) return 0;  // Check if n is of the form 2^k - 1
    int k = log2(n + 1);  // Depth of the tree
    if (k == 0) return 1;

    int numChildren = pow(2, k - 1);
    long long count = 1;
    for (int i = 0; i < k; i++) {
        count *= binomialCoeff(numChildren - 1, numChildren / 2);
        numChildren /= 2;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << countValidDFSOrders(n) << endl;
    return 0;
}
