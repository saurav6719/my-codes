#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the index where the target element is found
        }
    }
    return -1;  // Return -1 if the target element is not found
}

int main() {
    int arr[] = {10, 25, 4, 42, 8, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 42;

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }

    return 0;
}
