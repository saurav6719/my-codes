#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int L, int R) {
    return uniform_int_distribution<int>(L, R)(rng);
}

char getRandChar() {
    return (getRand(0, 1) == 0) ? 'B' : 'G';
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <T> <minN> <maxN> <maxK>\n";
        return 1;
    }
    
    int maxN = stoi(argv[1]);
    int maxK = stoi(argv[2]);
    int T = 1;

    cout << T << "\n";

    while (T--) {
        int N = getRand(1, maxN);
        int K = getRand(0, maxK);

        cout << N << " " << K << "\n";

        for (int i = 0; i < N; ++i) {
            cout << getRand(0,1e9) << " ";
        }
        cout << "\n";
    }
    return 0;
}
