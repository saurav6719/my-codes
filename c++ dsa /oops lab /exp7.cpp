#include <iostream>
using namespace std;
//7.	Write a C++ program to perform different arithmetic operation such as addition, subtraction, division, modulus and multiplication using inline function.

inline double add(double a, double b) {
    return a + b;
}

inline double subtract(double a, double b) {
    return a - b;
}

inline double multiply(double a, double b) {
    return a * b;
}

inline double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "Cannot divide by zero." << endl;
        return 0;
    }
}

inline int integerModulus(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        cout << "Cannot find modulus with zero divisor." << endl;
        return 0;
    }
}

int main() {
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Addition: " << add(num1, num2) << endl;
    cout << "Subtraction: " << subtract(num1, num2) << endl;
    cout << "Multiplication: " << multiply(num1, num2) << endl;
    cout << "Division: " << divide(num1, num2) << endl;
    
    int intNum1, intNum2;
    cout << "Enter two integers: ";
    cin >> intNum1 >> intNum2;

    cout << "Integer Modulus: " << integerModulus(intNum1, intNum2) << endl;

    return 0;
}