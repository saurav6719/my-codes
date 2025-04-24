#include <stdio.h>
#include<stdlib.h>
#include<math.h>

// Define a structure to represent a polynomial term
struct Term {
    int coefficient;
    int exponent;
};

// Function to display a polynomial
void displayPolynomial(struct Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            if (poly[i].coefficient >= 0)
                printf(" + ");
            else
                printf(" - ");
        }
        printf("%d", abs(poly[i].coefficient));

        if (poly[i].exponent > 0)
            printf("x^%d", poly[i].exponent);
    }
    printf("\n");
}
int evaluate(struct Term polynomial[], int n, int x){
    int result = 0;
    for(int i = 0 ; i<n ; i++){
        if (polynomial[i].exponent > 0) result += (polynomial[i].coefficient) * pow(x,polynomial[i].exponent);
        if (polynomial[i].exponent == 0) result += (polynomial[i].coefficient);
    }
    return result;
}
int main() {
    // Define a polynomial 3x^2 - 2x + 5
    struct Term polynomial[] = { {3, 2},{-2, 1},{5, 0}};

    int numTerms = sizeof(polynomial) / sizeof(polynomial[0]);

    printf("Polynomial: ");
    displayPolynomial(polynomial, numTerms);
    int result = evaluate(polynomial, numTerms, 2);
    printf("%d", result);
    return 0;
}
