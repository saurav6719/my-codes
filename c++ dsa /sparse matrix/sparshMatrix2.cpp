#include <iostream>
using namespace std;

// Define a struct to represent a non-zero element in the matrix
struct MatrixElement {
    int row;
    int col;
    int value;
};

// Function to convert a dense matrix into a sparse matrix
void createSparseMatrix(int denseMatrix[4][6], MatrixElement sparseMatrix[], int &numElements) {
    numElements = 0;

    // Iterate through the dense matrix to find non-zero elements
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            if (denseMatrix[i][j] != 0) {
                sparseMatrix[numElements].row = i;
                sparseMatrix[numElements].col = j;
                sparseMatrix[numElements].value = denseMatrix[i][j];
                numElements++;
            }
        }
    }
}

// Function to print the sparse matrix
void printSparseMatrix(MatrixElement sparseMatrix[], int numElements) {
    cout << "Row\tColumn\tValue" << endl;
    for (int i = 0; i < numElements; i++) {
        cout << sparseMatrix[i].row << "\t" << sparseMatrix[i].col << "\t" << sparseMatrix[i].value << endl;
    }
}

int main() {
    int denseMatrix[4][6] = {
        {0, 0, 0, 0, 5, 0},
        {9, 0, 3, 0, 0, 0},
        {0, 0, 0, 8, 7, 0},
        {0, 13, 0, 0, 0, 2}
    };

    MatrixElement sparseMatrix[100]; // Assuming a maximum of 100 non-zero elements
    int numElements;

    // Convert the dense matrix to a sparse matrix
    createSparseMatrix(denseMatrix, sparseMatrix, numElements);

    cout << "Sparse Matrix in Triplet Form:" << endl;
    printSparseMatrix(sparseMatrix, numElements);

    return 0;
}
