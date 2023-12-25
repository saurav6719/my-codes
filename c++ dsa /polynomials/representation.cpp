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

            if (polynomial[i].exponent > 0)
                cout << "x^" << polynomial[i].exponent;
        }
        cout << endl;
}
int main(){
    class term polynomial[]   = {{3,2}, {-2,1}, {5,0}};
    int n = sizeof(polynomial)/ sizeof(polynomial[0]);
    display(polynomial, n);
    return 0;
}