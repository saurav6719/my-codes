#include <bits/stdc++.h>
using namespace std;

// Function to trim spaces from the beginning and end of a string
string trim(const string &s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    return (start == string::npos) ? "" : s.substr(start, end - start + 1);
}

bool is_valid_solution(ifstream &input, ifstream &optimal, ifstream &brute) {
    // Read the expected output from brute force
    string expected;
    vector<string> expected_output;
    while (getline(brute, expected)) {
        expected_output.push_back(trim(expected)); // Trim spaces
    }

    // Read the solution output from optimal solution
    string given;
    vector<string> given_output;
    while (getline(optimal, given)) {
        given_output.push_back(trim(given)); // Trim spaces
    }

    // note that both are strings so need to convert to integers if require to compare

    // If both outputs are exactly the same, it's valid
    if (given_output == expected_output) return true;

    return false;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cerr << "Usage: ./checker <test_case> <optimal_output> <brute_output>\n";
        return 1;
    }

    ifstream input(argv[1]); // Test case
    ifstream optimal(argv[2]); // Output from optimal
    ifstream brute(argv[3]); // Output from brute-force

    if (!input || !optimal || !brute) {
        cerr << "Error opening files\n";
        return 1;
    }

    if (is_valid_solution(input, optimal, brute)) {
        return 0; // Correct
    } else {
        cerr << "❌ Incorrect solution!\n";
        return 1; // Incorrect
    }
}
