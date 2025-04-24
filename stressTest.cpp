#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function to generate a random grid with integers between 1 and 10^6
vector<vector<int>> generate_random_grid(int rows, int cols) {
    vector<vector<int>> grid(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = rand() % 1000000 + 1; // Random integer between 1 and 10^6
        }
    }
    return grid;
}

// Function to generate a random test case in the specified format
string generate_test_case() {
    int t = 10; // Number of test cases (adjust as needed)
    string test_case = to_string(t) + "\n";
    
    for (int i = 0; i < t; ++i) {
        int n = rand() % 10 + 1; // Array size between 1 and 10
        test_case += to_string(n) + "\n";
        
        // Generate the 1D array with random numbers in [-1000, 1000]
        for (int j = 0; j < n; ++j) {
            int val = rand() % 2001 - 1000; // rand() % 2001 gives 0 to 2000, subtract 1000 to get [-1000, 1000]
            test_case += to_string(val) + " ";
        }
        test_case += "\n";
    }
    
    return test_case;
}


// Function to write a test case to a file
void write_test_case(const string& test_case) {
    ofstream input_file("input.txt");
    input_file << test_case;
    input_file.close();
}

// Function to run the brute force and optimized solutions and compare their output
bool run_and_compare() {
    // Run brute force solution
    system("./brute < input.txt > output_brute.txt");

    // Run optimized solution
    system("./optimised < input.txt > output_optimized.txt");

    // Compare outputs
    ifstream brute_file("output_brute.txt");
    ifstream optimized_file("output_optimized.txt");

    string brute_output, optimized_output;

    getline(brute_file, brute_output);
    getline(optimized_file, optimized_output);

    brute_file.close();
    optimized_file.close();

    return brute_output == optimized_output;
}

int main() {
    srand(time(0)); // Seed for random number generator

    // Print current directory for debugging
    system("pwd");

    // Compile both solutions and check for errors
    if (system("g++ ./brute.cpp -o brute") != 0) {
        cout << "Failed to compile brute.cpp" << endl;
        return 1;
    }
    if (system("g++ ./optimised.cpp -o optimised") != 0) {
        cout << "Failed to compile optimised.cpp" << endl;
        return 1;
    }

    for (int i = 1; i <= 1000; ++i) { // Run the test for a large number of iterations
        cout << "Running test case #" << i << endl;

        // Generate a random test case
        string test_case = generate_test_case();

        // Write the test case to an input file
        write_test_case(test_case);

        // Compare the outputs
        if (!run_and_compare()) {
            cout << "Test case failed on iteration " << i << "!" << endl;
            cout << "Test case:" << endl;
            cout << test_case << endl;

            // Output the brute and optimized outputs for debugging
            cout << "Brute-force output:" << endl;
            system("cat output_brute.txt");

            cout << "Optimized output:" << endl;
            system("cat output_optimized.txt");

            break; // Exit if a mismatch is found
        }
    }

    cout << "All test cases passed!" << endl;
    return 0;
}
