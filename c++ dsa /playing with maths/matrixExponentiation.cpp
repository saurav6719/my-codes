#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;

vector<vector<int>> matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B, int mod = MOD) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod;
            }
        }
    }
    return C;
}

vector<vector<int>> matrixExponentiate(vector<vector<int>> base, int exp, int mod = MOD){
    int n = base.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    
    // Initialize result as the identity matrix
    for (int i = 0; i < n; ++i) {
        result[i][i] = 1;
    }

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = matrixMultiply(result, base, mod);
            exp--;
            continue;
        }
        base = matrixMultiply(base, base, mod);
        exp /= 2;
    }

    return result;
}

int32_t main() {
    // Example: Fibonacci numbers using matrix exponentiation
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> F = {{1, 1}, {1, 0}};
    
    vector<vector<int>> result = matrixExponentiate(F, n - 1);

    cout << result[0][0] << endl; // This will print the nth Fibonacci number

    return 0;
}
