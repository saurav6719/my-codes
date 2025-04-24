
#include <stdio.h>
#include<stdlib.h>

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

        if (poly[i].exponent > 0) printf("x^%d", poly[i].exponent);
        if (poly[i].exponent == 0) break;
    }
    printf("\n");
}

void addition(struct Term polynomial1[],struct Term polynomial2[], struct Term result[], int n, int m ){
    int i = 0; 
    int j = 0; 
    int k = 0;

    while(i<n && j<m){
        if(polynomial1[i].exponent > polynomial2[j].exponent) result[k++] = polynomial1[i++];
        else if(polynomial1[i].exponent < polynomial2[j].exponent) result[k++] = polynomial2[j++];
        else {
            result[k].exponent = polynomial1[i].exponent;
            result[k++].coefficient = polynomial1[i++].coefficient + polynomial2[j++].coefficient;
        }
    }
    while(i<n){
        result[k++]= polynomial1[i++];
    }
    while(j<m){
        result[k++]= polynomial2[j++];
    }
}
int main() {
    
    struct Term polynomial1[]   = {{5,4}, {2,2}, {5,0}};
    struct Term polynomial2[]   = {{6,4}, {5,3}, {9,2},{2,1}, {3,0}};
    
    int n = sizeof(polynomial1) / sizeof(polynomial1[0]);
    int m = sizeof(polynomial2) / sizeof(polynomial2[0]);

    struct Term result[m+n];

    
    displayPolynomial(polynomial1, n);
    displayPolynomial(polynomial2, m);
    addition(polynomial1, polynomial2, result, n, m);
    displayPolynomial(result, m+n);
    return 0;

}
