#!/bin/bash

#how to run this file
#go to strees test folder if not by cd Stre tab 
#./stress_test.sh


# Default constraints if not provided
N=${1:-10000}        # Default array size
Q=${4:-500}       # Default number of queries (if needed)
MIN_VAL=${3:-1}   # Default min array value
MAX_VAL=${2:-100} # Default max array value
MAX_X=${6:-1000} # Default max value of x
MIN_X=${5:--1000} # Default min value of x

#note beware of spaces in between 
# arrange {x:-y} x is argument number you are passing y is value 
# Ensure the failed cases directory exists
mkdir -p failed_cases

# Compile all C++ programs
g++-13 -std=c++17 -O2 -o generator generator.cpp
g++-13 -std=c++17 -O2 -o validator validator.cpp
g++-13 -std=c++17 -O2 -o optimal optimal.cpp
g++-13 -std=c++17 -O2 -o brute brute.cpp
g++-13 -std=c++17 -O2 -o checker checker.cpp  

while true; do
    echo -e "\n🔹 Generating test case..."

    # Generate a test case
    ./generator "$N" > test_case.txt

    # i am giving only 1 test and running infintely 

    # Validate test case
    if ! ./validator < test_case.txt; then
        echo -e "\n❌ Test case failed validation! ❌"
        echo "Check test_case.txt for details."
        exit 1
    fi

    # Run both solutions
    ./optimal < test_case.txt > optimal_output.txt
    ./brute < test_case.txt > brute_output.txt

    # Compare outputs
    if ! ./checker test_case.txt optimal_output.txt brute_output.txt; then
        TIMESTAMP=$(date +%s)    # Unique timestamp for failed case

        echo -e "\n🚨 Mismatch found! 🚨"
        echo "===================================="
        echo "🔹 Input:"
        cat test_case.txt
        echo "===================================="
        echo "✅ Optimal Output:"
        cat optimal_output.txt
        echo "===================================="
        echo "❌ Brute Force Output:"
        cat brute_output.txt
        echo "===================================="

        # Save failed test case for debugging
        cp test_case.txt failed_cases/failed_case_${TIMESTAMP}.txt
        exit 1
    fi
done

echo -e "\n✅ No failing case found after multiple attempts."
