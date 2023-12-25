#include<iostream>
using namespace std;
class term{
    public:
    int coefficient;
    int exponent;

};
void display( class term polynomial[], int n) {
        for (int i = 0; i < n; i++) {
            if (polynomial[i].exponent == -1) continue;
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
void multiplication(class term polynomial1[],class term polynomial2[], class term result[], int n, int m ){
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
int main(){
    class term polynomial1[]   = {{5,4}, {2,2}, {5,0}};
    class term polynomial2[]   = {{6,4}, {5,3}, {9,2},{2,1}, {3,0}};
    int n = sizeof(polynomial1)/ sizeof(polynomial1[0]);
    int m = sizeof(polynomial2)/ sizeof(polynomial2[0]);
    display(polynomial1, n);
    display(polynomial2, m);
    class term result[m*n];
    multiplication(polynomial1, polynomial2, result, n, m);
    display(result,m*n);
    return 0;
}