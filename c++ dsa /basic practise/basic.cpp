#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap them if they are in the wrong order
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    // Example usage
    vector<int> myArray = {64, 25, 12, 22, 11};

    cout << "Original Array: ";
    for (const int& num : myArray) {
        cout << num << " ";
    }
    cout << endl;

    // Perform Bubble Sort
    bubbleSort(myArray);

    cout << "Sorted Array: ";
    for (const int& num : myArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
