#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int L, int R) {
    return uniform_int_distribution<int>(L, R)(rng);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {  // We now require 3 parameters + program name
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

    while (T--) {
        // Generate array
        cout << n << "\n";
        for (int i = 0; i < n; i++) {
            cout << getRand(minVal, maxVal) << " ";
        }
        cout << "\n";

        for(int i = 0; i < n; i++) {
            cout << getRand(minVal, maxVal) << " ";
        }
        cout << "\n";
    }

    return 0;
}

//open terminal and run the following command
//g++ generator.cpp -o generator
