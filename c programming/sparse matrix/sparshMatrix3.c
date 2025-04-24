#include <stdio.h>

// Define a struct to represent a non-zero element in the matrix
struct MatrixElement {
    int row;
    int col;
    int value;
};

// Function to add two sparse matrices
void addSparseMatrices(const struct MatrixElement* matrix1, int numElements1, const struct MatrixElement* matrix2, int numElements2, struct MatrixElement* result, int* numElementsResult) {
    int i = 0, j = 0, k = 0;

    while (i < numElements1 && j < numElements2) {
        if (matrix1[i].row < matrix2[j].row || (matrix1[i].row == matrix2[j].row && matrix1[i].col < matrix2[j].col)) {
            result[k] = matrix1[i];
            i++;
        } else if (matrix1[i].row > matrix2[j].row || (matrix1[i].row == matrix2[j].row && matrix1[i].col > matrix2[j].col)) {
            result[k] = matrix2[j];
            j++;
        } else { // Elements are at the same position
            result[k] = matrix2[j];
            result[k].value += matrix1[i].value;
            i++;
            j++;
        }
        k++;
    }

    while (i < numElements1) {
        result[k] = matrix1[i];
        i++;
        k++;
    }

    while (j < numElements2) {
        result[k] = matrix2[j];
        j++;
        k++;
    }

    *numElementsResult = k;
}

// Function to print the sparse matrix
void printSparseMatrix(const struct MatrixElement* matrix, int numElements) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < numElements; i++) {
        printf("%d\t%d\t%d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

int main() {
    struct MatrixElement matrix1[] = {
        {1,4,6},
        {2,2,7},
        {3,2,2},
        {2,4,5},
        {5,1,4}
    };
    int numElements1 = sizeof(matrix1) / sizeof(matrix1[0]);

    struct MatrixElement matrix2[] = {
       {2,2,3},
       {2,5,5},
       {3,3,2},
       {3,6,7},
       {4,4,9},
       {5,1,8}
    };
    int numElements2 = sizeof(matrix2) / sizeof(matrix2[0]);

    // Initialize the result matrix
    struct MatrixElement result[1000]; // Assuming a maximum of 100 non-zero elements
    int numElementsResult;

    // Check if the matrices can be added
    if (numElements1 == 0 || numElements2 == 0) {
        printf("Matrices cannot be added because one or both of them are empty.\n");
        return 1;
    }

    // Add the sparse matrices
    addSparseMatrices(matrix1, numElements1, matrix2, numElements2, result, &numElementsResult);

    // Print the resulting sparse matrix
    printf("Resulting Sparse Matrix:\n");
    printSparseMatrix(result, numElementsResult);

    return 0;
}
