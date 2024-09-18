#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

// Function to generate a random test case
string generate_test_case() {
    int n = rand() % 10 + 1; // random number between 1 and 1000 (adjust as needed)
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 50 + 1; // random number between 1 and 100
    }

    // Creating a string in the format of a test case (adjust according to your problem)
    string test_case = to_string(n) + "\n";
    for (int i = 0; i < n; ++i) {
        test_case += to_string(arr[i]) + " ";
    }
    test_case += "\n";
    
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

    for (int i = 1; i <= 10; ++i) { // Run the test for a large number of iterations
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
