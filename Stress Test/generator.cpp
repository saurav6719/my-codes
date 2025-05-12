#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int L, int R) {
    return uniform_int_distribution<int>(L, R)(rng);
}

int main(int argc, char* argv[]) {
    if (argc < 1) {
        cerr << "Usage: " << argv[0] << " <T> <n> <maxVal> <q> <maxX>\n";
        return 1;
    }

    int T = 1;

    while (T--) {
        int n = getRand(4, 10);  // or read from argv if needed
        cout<< n << "\n";

        // Generate permutation of size n
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 1); // fill with 1 to n

        shuffle(perm.begin(), perm.end(), rng); // random shuffle using rng

        // print the permutation
        for (int x : perm) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
