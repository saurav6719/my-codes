#include <iostream>
#include <vector>
using namespace std;

// Define a struct to represent a non-zero element in the matrix
struct MatrixElement {
    int row;
    int col;
    int value;
};

// Function to find the transpose of a sparse matrix
vector<MatrixElement> transposeSparseMatrix(const vector<MatrixElement>& matrix) {
    vector<MatrixElement> transpose;
    int numRows = 0, numCols = 0;

    // Find the number of rows and columns in the original matrix
    for (const MatrixElement& element : matrix) {
        numRows = max(numRows, element.row + 1);
        numCols = max(numCols, element.col + 1);
    }

    // Initialize a 2D array to store the elements of the transpose
    vector<vector<int>> transposeArray(numCols, vector<int>(numRows, 0));

    // Fill the transposeArray with the values from the original matrix
    for (const MatrixElement& element : matrix) {
        transposeArray[element.col][element.row] = element.value;
    }

    // Create the transpose sparse matrix from transposeArray
    for (int col = 0; col < numCols; col++) {
        for (int row = 0; row < numRows; row++) {
            if (transposeArray[col][row] != 0) {
                MatrixElement transposedElement;
                transposedElement.row = row;
                transposedElement.col = col;
                transposedElement.value = transposeArray[col][row];
                transpose.push_back(transposedElement);
            }
        }
    }

    return transpose;
}

// Function to print the sparse matrix
void printSparseMatrix(const vector<MatrixElement>& matrix) {
    cout << "Row\tColumn\tValue" << endl;
    for (const MatrixElement& element : matrix) {
        cout << element.row << "\t" << element.col << "\t" << element.value << endl;
    }
}

int main() {
    vector<MatrixElement> matrix = {
        {0, 0, 1},
        {0, 1, 2},
        {1, 0, 3},
        {1, 2, 4},
        {2, 1, 5}
    };

    cout << "Original Sparse Matrix:" << endl;
    printSparseMatrix(matrix);

    // Find the transpose of the sparse matrix
    vector<MatrixElement> transpose = transposeSparseMatrix(matrix);

    cout << "Transpose of the Sparse Matrix:" << endl;
    printSparseMatrix(transpose);

    return 0;
}
