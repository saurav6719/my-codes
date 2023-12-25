#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a non-zero element in the matrix
struct MatrixElement {
    int row;
    int col;
    int value;
};

// Function to find the transpose of a sparse matrix
void transposeSparseMatrix(const struct MatrixElement* matrix, int numElements, struct MatrixElement* transpose, int* numTransposeElements) {
    int numRows = 0, numCols = 0;

    // Find the number of rows and columns in the original matrix
    for (int i = 0; i < numElements; i++) {
        if (matrix[i].row >= numRows) {
            numRows = matrix[i].row + 1;
        }
        if (matrix[i].col >= numCols) {
            numCols = matrix[i].col + 1;
        }
    }

    *numTransposeElements = 0;

    // Create the transpose of the sparse matrix
    for (int col = 0; col < numCols; col++) {
        for (int row = 0; row < numRows; row++) {
            for (int i = 0; i < numElements; i++) {
                if (matrix[i].row == row && matrix[i].col == col) {
                    transpose[*numTransposeElements].row = col;
                    transpose[*numTransposeElements].col = row;
                    transpose[*numTransposeElements].value = matrix[i].value;
                    (*numTransposeElements)++;
                }
            }
        }
    }
}

// Function to print the sparse matrix
void printSparseMatrix(const struct MatrixElement* matrix, int numElements) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < numElements; i++) {
        printf("%d\t%d\t%d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

int main() {
    struct MatrixElement matrix[] = {
        {0, 0, 1},
        {0, 1, 2},
        {1, 0, 3},
        {1, 2, 4},
        {2, 1, 5}
    };
    int numElements = sizeof(matrix) / sizeof(matrix[0]);

    printf("Original Sparse Matrix:\n");
    printSparseMatrix(matrix, numElements);

    // Initialize the transpose matrix
    struct MatrixElement transpose[1000]; // Assuming a maximum of 1000 non-zero elements in the transpose
    int numTransposeElements;

    // Find the transpose of the sparse matrix
    transposeSparseMatrix(matrix, numElements, transpose, &numTransposeElements);

    printf("Transpose of the Sparse Matrix:\n");
    printSparseMatrix(transpose, numTransposeElements);

    return 0;
}
