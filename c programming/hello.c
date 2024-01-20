#include <stdio.h>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numbers[] = {4, 2, 7, 1, 9};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Displaying the array before sorting
    printf("Array before sorting: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", numbers[i]);
    }

    // Sorting the array
    bubbleSort(numbers, size);

    // Displaying the array after sorting
    printf("\nArray after sorting: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
