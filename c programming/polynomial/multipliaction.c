

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
        if (poly[i].exponent == -1) continue;
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
void multiplication(struct Term polynomial1[],struct Term polynomial2[], struct Term result[], int n, int m ){
    int k = 0;
    for(int i = 0; i< n ; i++){
        for(int j = 0; j<m; j++){
            result[k].exponent = polynomial1[i].exponent + polynomial2[j].exponent;
            result[k++].coefficient = polynomial1[i].coefficient * polynomial2[j].coefficient;
        }
    }

    for(int x = 0; x< m*n; x++){
        if (result[x].exponent == -1) continue;
        for(int y = x+1 ; y< m*n; y++){
            if(result[y].exponent == -1) continue;
            if(result[y].exponent == result[x]. exponent){
                result[x].coefficient += result[y]. coefficient;
                result[y].exponent = -1;
            }

        }
    }
    
}
int main() {
    
    struct Term polynomial1[]   = {{5,4}, {2,2}, {5,0}};
    struct Term polynomial2[]   = {{6,4}, {5,3}, {9,2},{2,1}, {3,0}};
    
    int n = sizeof(polynomial1) / sizeof(polynomial1[0]);
    int m = sizeof(polynomial2) / sizeof(polynomial2[0]);

    struct Term result[m*n];

    
    displayPolynomial(polynomial1, n);
    displayPolynomial(polynomial2, m);
    multiplication(polynomial1, polynomial2, result, n, m);
    displayPolynomial(result, m*n);
    return 0;

}
