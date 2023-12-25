#include <iostream>
using namespace std;
//2.	Create a class called 'Employee' that has “Empnumber‟ and “Empname‟ as data members and member functions getdata( ) to input data display() to output data. Write a main function to create an array of ‟Employee‟ objects. Accept and print and accept the details of at least 6 employees.


class Employee {
public:
    int Empnumber;
    string Empname;

    void getdata() {
        cout << "Enter Employee Number: ";
        cin >> Empnumber;
        cout << "Enter Employee Name: ";
        cin >> Empname;
    }

    void display() {
        cout << "Employee Number: " << Empnumber << endl;
        cout << "Employee Name: " << Empname << endl;
    }
};

int main() {
    using namespace std;
    Employee employees[6];

    for (int i = 0; i < 6; i++) {
        employees[i].getdata();
    }

    for (int i = 0; i < 6; i++) {
        employees[i].display();
    }

    return 0;
}