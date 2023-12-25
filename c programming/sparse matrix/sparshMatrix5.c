#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a non-zero element in the matrix
struct MatrixElement {
    int row;
    int col;
    int value;
};

// Function to find the original of a sparse matrix
void originalMatrix(const struct MatrixElement* matrix, int numElements) {
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

    // creating a 2d matrix of zero elements 
    int originalMatrix[numRows][numCols];
    for(int i =0; i< numRows; i++){
        for(int j = 0; j< numCols ; j++){
            originalMatrix[i][j] = 0;
        }
    }

    //traverse in sparse matrix

    for(int i = 0 ; i< numElements; i++){
        originalMatrix[matrix[i].row][matrix[i].col]= matrix[i].value;
    }

    for(int i =0; i< numRows; i++){
        for(int j = 0; j< numCols ; j++){
            printf("%d ", originalMatrix[i][j]);
        }
        printf("\n");
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
    originalMatrix(matrix,numElements);
    return 0;
}
