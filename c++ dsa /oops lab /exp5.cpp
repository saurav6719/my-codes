#include <iostream>
using namespace std;
// 5.	Write a program to accept five different numbers by creating a class called friendfunc1 and friendfunc2 taking 2 and 3 arguments respectively and calculate the average of these numbers by passing object of the class to friend function.


class friendfunc2;  // Forward declaration

class friendfunc1 {
private:
    double num1, num2;

public:
    friendfunc1(double a, double b) : num1(a), num2(b) {}

    friend double calculateAverage(friendfunc1 obj1, friendfunc2 obj2);
};

class friendfunc2 {
private:
    double num1, num2, num3;

public:
    friendfunc2(double a, double b, double c) : num1(a), num2(b), num3(c) {}

    friend double calculateAverage(friendfunc1 obj1, friendfunc2 obj2);
};

double calculateAverage(friendfunc1 obj1, friendfunc2 obj2) {
    return (obj1.num1 + obj1.num2 + obj2.num1 + obj2.num2 + obj2.num3) / 5;
}

int main() {
    friendfunc1 obj1(1.0, 2.0);
    friendfunc2 obj2(3.0, 4.0, 5.0);

    double average = calculateAverage(obj1, obj2);

    cout << "Average of five numbers: " << average << endl;

    return 0;
}