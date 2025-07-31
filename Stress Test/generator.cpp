/**
 *    author: Saurav
 *    created: 2025.07.11
 *    Generator for random test case
 */

#include<bits/stdc++.h>
using namespace std;

#define int long long int

void generateTestCase(int n) {
    string s1, s2;
    srand(time(0));

    // Generate s1 and s2
    for(int i = 0; i < n; i++) {
        char c = (rand() % 2 == 0) ? 'N' : 'D';
        s1.push_back(c);
    }
    for(int i = 0; i < n; i++) {
        char c = (rand() % 2 == 0) ? 'N' : 'D';
        s2.push_back(c);
    }

    // Generate l and r
    int l = rand() % (n - 1) + 1; // 1 to n-1
    int r = rand() % (n - l) + (l + 1); // l+1 to n

    // Output
    cout << s1 << endl;
    cout << s2 << endl;
    cout << l << " " << r << endl;
}

signed main() {
    int n = 100000; // Example length, change as needed
    generateTestCase(n);
    return 0;
}
