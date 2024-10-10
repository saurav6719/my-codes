#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function to generate a random string of capital English letters 'A' to 'E'
string generate_random_string(int length) {
    string test_string;
    for (int i = 0; i < length; ++i) {
        char random_char = 'A' + rand() % 5; // Random letter from 'A' to 'E'
        test_string += random_char;
    }
    return test_string;
}

// Function to generate a random test case
string generate_test_case() {
    int t = rand() % 5 + 1; // Random number of test cases between 1 and 5 (adjust as needed)
    
    string test_case = to_string(t) + "\n"; // Start with the number of test cases
    for (int i = 0; i < t; ++i) {
        int string_length = rand() % 20 + 1; // Random string length between 1 and 20
        test_case += generate_random_string(string_length) + "\n";
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
