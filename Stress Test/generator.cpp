#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int L, int R) {
    return uniform_int_distribution<int>(L, R)(rng);
}

<<<<<<< HEAD
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
=======
int main(int argc, char* argv[]) {
    if (argc < 7) {  // We now require 5 parameters + program name
        cerr << "Usage: " << argv[0] << " <T> <n> <maxVal> <q> <maxX>\n";
        return 1;
    }

    // argc[0] is the program name
    // rest all are the parameters or contraints i need to pass 

    // int T = stoi(argv[1]);  // Number of test cases
    int T = 1;
    int n = stoi(argv[1]);  // Array size
    int maxVal = stoi(argv[2]);  // Max value in array
    int minVal = stoi(argv[3]);  // Min value in array
    int minX = stoi(argv[5]);  // Min value of x in query
    int maxX = stoi(argv[6]);  // Max value of x in query
    int q = stoi(argv[4]);  // Number of queries
    // cout << T << "\n";  // First line: number of test cases

    while (T--) {
        // Generate array
        

        cout << n << "\n";
        for (int i = 0; i < n; i++) {
            cout << getRand(minVal, maxVal) << " ";
        }
        cout << "\n";
    }

    cout<<q<<endl;

    while(q--){
        int l = getRand(1, n);
        int r = getRand(l, n);
        int x = getRand(minX, maxX);
        cout<<l<<" "<<r<<" "<<x<<endl;
    }

    return 0;
}

//open terminal and run the following command
//g++ generator.cpp -o generator
//./generator 1 5 10 3 5 > input.txt
>>>>>>> 2a644fa18ee9cad7d1b3f10abf85e98e62a67a4c
