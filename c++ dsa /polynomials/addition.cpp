#include<iostream>
using namespace std;
class term{
    public:
    int coefficient;
    int exponent;

};
void display( class term polynomial[], int n) {
        for (int i = 0; i < n; i++) {
            
            if (i != 0) {
                if (polynomial[i].coefficient >= 0)
                    cout << " + ";
                else
                    cout << " - ";
            }
            cout << abs(polynomial[i].coefficient);

            if (polynomial[i].exponent > 0) cout << "x^" << polynomial[i].exponent;
            if (polynomial[i].exponent == 0) break;
        }

        cout << endl;
}
void addition(class term polynomial1[],class term polynomial2[], class term result[], int n, int m ){
    int i = 0; 
    int j = 0; 
    int k = 0;

    while(i<n and j<m){
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
int main(){
    class term polynomial1[]   = {{5,4}, {2,2}, {5,0}};
    class term polynomial2[]   = {{6,4}, {5,3}, {9,2},{2,1}, {3,0}};
    int n = sizeof(polynomial1)/ sizeof(polynomial1[0]);
    int m = sizeof(polynomial2)/ sizeof(polynomial2[0]);
    display(polynomial1, n);
    display(polynomial2, m);
    class term result[m+n];
    addition(polynomial1, polynomial2, result, n, m);
    display(result,m+n);
    return 0;
}