#include <iostream>
#include <vector>
using namespace std;

// Define a struct to represent a non-zero element in the matrix
struct MatrixElement {
    int row;
    int col;
    int value;
};

// Function to add two sparse matrices
vector<MatrixElement> addSparseMatrices(vector<MatrixElement>& matrix1, vector<MatrixElement>& matrix2) {
    vector<MatrixElement> result;
    int i = 0, j = 0;

    while (i < matrix1.size() && j < matrix2.size()) {
        if (matrix1[i].row < matrix2[j].row || (matrix1[i].row == matrix2[j].row && matrix1[i].col < matrix2[j].col)) {
            result.push_back(matrix1[i]);
            i++;
        } else if (matrix1[i].row > matrix2[j].row || (matrix1[i].row == matrix2[j].row && matrix1[i].col > matrix2[j].col)) {
            result.push_back(matrix2[j]);
            j++;
        } else { // Elements are at the same position
            result.push_back(matrix1[i]);
            result.back().value += matrix2[j].value;
            i++;
            j++;
        }
    }

    while (i < matrix1.size()) {
        result.push_back(matrix1[i]);
        i++;
    }

    while (j < matrix2.size()) {
        result.push_back(matrix2[j]);
        j++;
    }

    return result;
}

// Function to print the sparse matrix
void printSparseMatrix(const vector<MatrixElement>& matrix) {
    cout << "Row\tColumn\tValue" << endl;
    for (const auto& element : matrix) {
        cout << element.row << "\t" << element.col << "\t" << element.value << endl;
    }
}

int main() {
    vector<MatrixElement> matrix1 = {
        {0, 0, 0},
        {1, 1, 2},
        {2, 2, 3}
    };

    vector<MatrixElement> matrix2 = {
        {0, 0, 0},
        {1, 1, 1},
        {2, 2, 2}
    };

    // Check if the matrices can be added
    if (matrix1.empty() || matrix2.empty()) {
        cout << "Matrices cannot be added because one or both of them are empty." << endl;
        return 1;
    }

    // Add the sparse matrices
    vector<MatrixElement> result = addSparseMatrices(matrix1, matrix2);

    // Print the resulting sparse matrix
    cout << "Resulting Sparse Matrix:" << endl;
    printSparseMatrix(result);

    return 0;
}
