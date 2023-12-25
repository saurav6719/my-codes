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
                    std::cout << " + ";
                else
                    std::cout << " - ";
            }
            std::cout << abs(polynomial[i].coefficient);

            if (polynomial[i].exponent > 0)
                std::cout << "x^" << polynomial[i].exponent;
        }
        std::cout << std::endl;
}

int evaluate(class term polynomial[], int n, int x){
    int result = 0;
    for(int i = 0 ; i<n ; i++){
        result += (polynomial[i].coefficient) * pow(x,polynomial[i].exponent);
    }
    return result;
}

int main(){
    class term polynomial[]   = {{3,2}, {-2,1}, {5,0}};
    int n = sizeof(polynomial)/ sizeof(polynomial[0]);
    display(polynomial, n);
    cout<<evaluate(polynomial,n,2);
    return 0;
}