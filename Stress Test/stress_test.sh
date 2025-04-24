<<<<<<< HEAD
# #!/bin/bash

# # How to run this file
# # Go to stress test folder and run:
# # ./stress_test.sh

# # Default constraints if not provided
# N=${1:-100000}
# Q=${2:-100000}
# MIN_VAL=${4:--1000000000}
# MAX_VAL=${3:-100000000}
# MIN_X=${5:--1000000000}
# MAX_X=${6:-1000000000}

# mkdir -p failed_cases

# if [[ "$OSTYPE" == "darwin"* ]]; then
#     TIME_CMD="/usr/bin/time -p"
#     TIMEOUT_CMD="gtimeout"
# else
#     TIME_CMD="/usr/bin/time -p"
#     TIMEOUT_CMD="timeout"
# fi

# {
#     g++-13 -std=c++17 -O2 -o generator generator.cpp
#     g++-13 -std=c++17 -O2 -o validator validator.cpp
#     g++-13 -std=c++17 -O2 -o optimal optimal.cpp
#     g++-13 -std=c++17 -O2 -o brute brute.cpp
#     g++-13 -std=c++17 -O2 -o checker checker.cpp  
# } 2> compile_log.txt

# if [ $? -ne 0 ]; then
#     echo "❌ Compilation failed. Check compile_log.txt"
#     exit 1
# fi

# if ! command -v $TIMEOUT_CMD &> /dev/null; then
#     echo "❌ Error: timeout command not found!"
#     exit 1
# fi

# trap "echo -e '\n🛑 Terminating stress test...'; exit 0" SIGINT

# test_case=1

# while true; do
#     echo "---------------------------------"
#     echo -e "\n🔹 Generating test case #$test_case..."

#     ((test_case++))

#     ./generator "$N" "$Q" "$MAX_VAL" "$MIN_VAL" "$MIN_X" "$MAX_X" > test_case.txt

#     if ! ./validator < test_case.txt; then
#         echo -e "\n❌ Test case failed validation! Exiting..."
#         exit 1
#     fi

#     # Run the optimal solution and capture execution time in milliseconds
#     $TIMEOUT_CMD 2s $TIME_CMD -o optimal_time.txt ./optimal < test_case.txt > optimal_output.txt 
#     optimal_status=$?
#     optimal_time=$(awk '/real/ {print $2 * 1000}' optimal_time.txt)
#     optimal_time=${optimal_time:-0}

#     # If optimal solution gets TLE, stop and print results
#     if [ $optimal_status -eq 124 ]; then
#         echo -e "\n🚨 Optimal solution got TLE!"
#         echo "🔹 Time taken before TLE:"
#         echo "  ❌  Optimal solution: ${optimal_time}ms (TLE)"
#         exit 1
#     fi

#     # If optimal solution fails, stop and print results
#     if [ $optimal_status -ne 0 ]; then
#         echo -e "\n🚨 Optimal solution failed (exit code: $optimal_status)!"
#         exit 1
#     fi

    

#     # Run the brute force solution and capture execution time in milliseconds
#     $TIMEOUT_CMD 2s $TIME_CMD -o brute_time.txt ./brute < test_case.txt > brute_output.txt
#     brute_status=$?
#     brute_time=$(awk '/real/ {print $2 * 1000}' brute_time.txt)
#     brute_time=${brute_time:-0}

#     # If brute force gets TLE, stop and print results
#     if [ $brute_status -eq 124 ]; then
#         echo -e "\n🚨 Brute force solution got TLE!"
#         echo "🔹 Time taken before TLE:"
#         echo "   ✅ Optimal solution: ${optimal_time}ms"
#         echo "   ❌ Brute force solution: ${brute_time}ms (TLE)"
#         exit 1
#     fi

#     # Validate outputs using the checker
#     if ! ./checker test_case.txt optimal_output.txt brute_output.txt; then
#         TIMESTAMP=$(date +%s)

#         echo -e "\n🚨 Mismatch found! 🚨"
#         echo "===================================="
#         echo "🔹 Input:"
#         cat test_case.txt
#         echo "===================================="
#         echo "🔹 Optimal Output:"
#         cat optimal_output.txt
#         echo "===================================="
#         echo "🔹 Brute Force Output:"
#         cat brute_output.txt
#         echo "===================================="

#         cp test_case.txt failed_cases/failed_case_${TIMESTAMP}.txt
#         exit 1
#     fi
#     echo "✅ Correct, testing next case..."
# done


=======
>>>>>>> 2a644fa18ee9cad7d1b3f10abf85e98e62a67a4c
#!/bin/bash

# How to run this file
# Go to stress test folder and run:
# ./stress_test.sh

# Default constraints if not provided
<<<<<<< HEAD


MAX_N=${1:-100}
MAX_K=${2:-100}

=======
N=${1:-100000}
Q=${4:-100000}
MIN_VAL=${3:--1000000000}
MAX_VAL=${2:-1000000000}
MIN_X=${5:--1000000000}
MAX_X=${6:-1000000000}
>>>>>>> 2a644fa18ee9cad7d1b3f10abf85e98e62a67a4c

mkdir -p failed_cases

if [[ "$OSTYPE" == "darwin"* ]]; then
    TIME_CMD="/usr/bin/time -p"
    TIMEOUT_CMD="gtimeout"
else
    TIME_CMD="/usr/bin/time -p"
    TIMEOUT_CMD="timeout"
fi

{
    g++-13 -std=c++17 -O2 -o generator generator.cpp
    g++-13 -std=c++17 -O2 -o validator validator.cpp
    g++-13 -std=c++17 -O2 -o optimal optimal.cpp
    g++-13 -std=c++17 -O2 -o brute brute.cpp
    g++-13 -std=c++17 -O2 -o checker checker.cpp  
} 2> compile_log.txt

if [ $? -ne 0 ]; then
    echo "❌ Compilation failed. Check compile_log.txt"
    exit 1
fi

if ! command -v $TIMEOUT_CMD &> /dev/null; then
    echo "❌ Error: timeout command not found!"
    exit 1
fi

trap "echo -e '\n🛑 Terminating stress test...'; exit 0" SIGINT

test_case=1

while true; do
    echo "---------------------------------"
    echo -e "\n🔹 Generating test case #$test_case..."

    ((test_case++))

<<<<<<< HEAD
    ./generator "$MAX_N" "$MAX_K" > test_case.txt
=======
    ./generator "$N" "$MAX_VAL" "$MIN_VAL" "$Q" "$MIN_X" "$MAX_X" > test_case.txt
>>>>>>> 2a644fa18ee9cad7d1b3f10abf85e98e62a67a4c

    if ! ./validator < test_case.txt; then
        echo -e "\n❌ Test case failed validation! Exiting..."
        exit 1
    fi

<<<<<<< HEAD
    # Run the optimal solution and capture execution time
    $TIMEOUT_CMD 2s $TIME_CMD -o optimal_time.txt ./optimal < test_case.txt > optimal_output.txt 
=======
    # Run the optimal solution and capture execution time in milliseconds
    $TIMEOUT_CMD 4s $TIME_CMD -o optimal_time.txt ./optimal < test_case.txt > optimal_output.txt 
>>>>>>> 2a644fa18ee9cad7d1b3f10abf85e98e62a67a4c
    optimal_status=$?
    optimal_time=$(awk '/real/ {print $2 * 1000}' optimal_time.txt)
    optimal_time=${optimal_time:-0}

<<<<<<< HEAD
    if [ $optimal_status -eq 124 ]; then
        echo -e "\n🚨 Optimal solution got TLE!"
        echo "  ❌ Time taken: ${optimal_time}ms (TLE)"
        exit 1
    fi

=======
>>>>>>> 2a644fa18ee9cad7d1b3f10abf85e98e62a67a4c
    if [ $optimal_status -ne 0 ]; then
        echo -e "\n🚨 Optimal solution failed (exit code: $optimal_status)!"
        exit 1
    fi

<<<<<<< HEAD
    # Run the brute force solution and capture execution time
    $TIMEOUT_CMD 2s $TIME_CMD -o brute_time.txt ./brute < test_case.txt > brute_output.txt
=======
    # Run the brute force solution and capture execution time in milliseconds
    $TIMEOUT_CMD 4s $TIME_CMD -o brute_time.txt ./brute < test_case.txt > brute_output.txt
>>>>>>> 2a644fa18ee9cad7d1b3f10abf85e98e62a67a4c
    brute_status=$?
    brute_time=$(awk '/real/ {print $2 * 1000}' brute_time.txt)
    brute_time=${brute_time:-0}

<<<<<<< HEAD
    if [ $brute_status -eq 124 ]; then
        echo -e "\n🚨 Brute force solution got TLE!"
        echo "   ✅ Optimal: ${optimal_time}ms"
        echo "   ❌ Brute: ${brute_time}ms (TLE)"
        exit 1
    fi

=======
    # If brute force gets TLE, stop and print results
    if [ $brute_status -eq 124 ]; then
        echo -e "\n🚨 Brute force solution got TLE!"
        echo "🔹 Time taken before TLE:"
        echo "   ✅ Optimal solution: ${optimal_time}ms"
        echo "   ❌ Brute force solution: ${brute_time}ms (TLE)"
        exit 1
    fi

    # Validate outputs using the checker
>>>>>>> 2a644fa18ee9cad7d1b3f10abf85e98e62a67a4c
    if ! ./checker test_case.txt optimal_output.txt brute_output.txt; then
        TIMESTAMP=$(date +%s)

        echo -e "\n🚨 Mismatch found! 🚨"
        echo "===================================="
        echo "🔹 Input:"
        cat test_case.txt
        echo "===================================="
        echo "🔹 Optimal Output:"
        cat optimal_output.txt
        echo "===================================="
        echo "🔹 Brute Force Output:"
        cat brute_output.txt
        echo "===================================="

        cp test_case.txt failed_cases/failed_case_${TIMESTAMP}.txt
        exit 1
    fi
<<<<<<< HEAD

    echo "✅ Correct, testing next case..."
done

=======
    echo "✅ Correct, testing next case..."
done
>>>>>>> 2a644fa18ee9cad7d1b3f10abf85e98e62a67a4c
