#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int L, int R) {
    return uniform_int_distribution<int>(L, R)(rng);
}

int main(int argc, char* argv[]) {
    if (argc < 1) {  // We now require 3 parameters + program name
        cerr << "Usage: " << argv[0] << " <T> <n> <maxVal> <q> <maxX>\n";
        return 1;
    }

    // argc[0] is the program name
    // rest all are the parameters or contraints i need to pass 

    int T = 1;  // Number of test cases

    while (T--) {
        // Generate array
        int n = getRand(1, 999999);
        int a = getRand(2, 10000);
        int b = getRand(1, 10000);
        cout << n << "\n";
        cout << a << "\n";
        cout << b << "\n";
    }

    return 0;
}

//open terminal and run the following command
//g++ generator.cpp -o generator
