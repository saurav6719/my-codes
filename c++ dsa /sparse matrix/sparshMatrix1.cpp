#include <iostream>
using namespace std;
struct Triplet {
    int row;
    int col;
    int value;
};

const int MAX_ELEMENTS = 100; // Maximum number of non-zero elements

void matrixToTriplet(int matrix[4][6], int rows, int cols, Triplet triplet[MAX_ELEMENTS], int &num_elements) {
    int count = 0;

    // Fill the triplet representation
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                triplet[count].row = i;
                triplet[count].col = j;
                triplet[count].value = matrix[i][j];
                count++;
            }
        }
    }

    num_elements = count;
}

void printTriplet(Triplet triplet[MAX_ELEMENTS], int num_elements) {
    cout << "Row\tColumn\tValue" << std::endl;
    for (int i = 0; i < num_elements; i++) {
        std::cout << triplet[i].row << '\t' << triplet[i].col << '\t' << triplet[i].value << endl;
    }
}

int main() {
    int matrix[4][6] = {
        {0, 0, 0, 0, 5, 0},
        {9, 0, 3, 0, 0, 0},
        {0, 0, 0, 8, 7, 0},
        {0, 13, 0, 0, 0, 2}
    };

    Triplet triplet[MAX_ELEMENTS];
    int num_elements;

    matrixToTriplet(matrix, 4, 6, triplet, num_elements);

    cout << "Sparse Matrix in Triplet Form:" << std::endl;
    printTriplet(triplet, num_elements);

    return 0;
}
