#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(0)); // Seed for randomness

    // Generate random n between 1 and 10
    int n = rand() % 10 + 1;
    
    // Generate random x between 0 and n
    int x = rand() % (n + 1);

    cout << n << " " << x << "\n";

    // Generate n aura points between 0 and 20
    for (int i = 0; i < n; i++) {
        int a = rand() % 21;
        cout << a << (i + 1 == n ? '\n' : ' ');
    }

    return 0;
}
