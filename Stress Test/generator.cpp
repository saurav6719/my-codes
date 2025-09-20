/**
 *    author: Saurav
 *    created: 2025.07.11
 *    Generator for random test case
 */

#include<bits/stdc++.h>
using namespace std;

#define int long long int

void generateTestCase() {
    int n,x;
    n = rand() % 1000000000 + 1; // Random n between 1 and 10^9
    x = rand() % (n-1) + 1; // Random x between 1 and n-1
    cout << n << " " << x << endl;
}

signed main() {
    srand(time(0)); // Seed for random number generation
    generateTestCase();
    return 0;
}
