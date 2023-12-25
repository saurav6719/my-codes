#include <iostream>
using namespace std;
//3.	Write a C++ program to swap two number by both call by value and call by reference mechanism, using two functions swap_value() and swap_reference respectively , by getting the choice from the user and executing the user’s choice by switch-case.


class NumberSwapper {
public:
    void swap_value(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void swap_reference(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};

int main() {
    using namespace std;
    NumberSwapper swapper;
    int num1, num2;
    int choice;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Choose the swap method (1 for by value, 2 for by reference): ";
    cin >> choice;

    if (choice == 1) {
        swapper.swap_value(num1, num2);
    } else if (choice == 2) {
        swapper.swap_reference(num1, num2);
    }

    cout << "After swapping: " << num1 << " " << num2 << endl;

    return 0;
}