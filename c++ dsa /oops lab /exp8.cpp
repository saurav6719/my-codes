#include <iostream>
using namespace std;
//8.	WAP to return absolute value of variable types integer and float using function overloading .
int absolute(int num) {
    return (num < 0) ? -num : num;
}

float absolute(float num) {
    return (num < 0) ? -num : num;
}

int main() {
    int intNum;
    float floatNum;
    
    cout << "Enter an integer: ";
    cin >> intNum;
    cout << "Absolute value of integer: " << absolute(intNum) << endl;

    cout << "Enter a float: ";
    cin >> floatNum;
    cout << "Absolute value of float: " << absolute(floatNum) << endl;

    return 0;
}