#include <stdio.h>

struct Triplet {
    int row;
    int col;
    int value;
};

#define MAX_ELEMENTS 100  // Maximum number of non-zero elements

void matrixToTriplet(int matrix[4][6], int rows, int cols, struct Triplet triplet[MAX_ELEMENTS], int *num_elements) {
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

    *num_elements = count;
}

void printTriplet(struct Triplet triplet[MAX_ELEMENTS], int num_elements) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%d\t%d\t%d\n", triplet[i].row, triplet[i].col, triplet[i].value);
    }
}

int main() {
    int matrix[4][6] = {
        {0, 0, 0, 0, 5, 0},
        {9, 0, 3, 0, 0, 0},
        {0, 0, 0, 8, 7, 0},
        {0, 13, 0, 0, 0, 2}
    };

    struct Triplet triplet[MAX_ELEMENTS];
    int num_elements;

    matrixToTriplet(matrix, 4, 6, triplet, &num_elements);

    printf("Sparse Matrix in Triplet Form:\n");
    printTriplet(triplet, num_elements);

    return 0;
}

