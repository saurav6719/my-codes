const int MOD = 1e9 + 7;

// Function to calculate power in modular arithmetic
long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1; // y = y/2
        x = (x * x) % MOD;
    }
    return res;
}

// Function to calculate factorial in modular arithmetic
long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; ++i)
        res = (res * i) % MOD;
    return res;
}

// Function to calculate nCr in modular arithmetic
long long nCr(int n, int r) {
    if (r == 0 || r == n)
        return 1;
    long long numerator = factorial(n);
    long long denominator = (factorial(r) * factorial(n - r)) % MOD;
    return (numerator * power(denominator, MOD - 2)) % MOD;
}