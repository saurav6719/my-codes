#include <iostream>
using namespace std;
//6.	Write a program to accept the student detail such as name and 3 different marks by get_data() method and display the name and average of marks using display() method. Define a friend class for calculating the average of marks using the method mark_avg().


class Student;  // Forward declaration

class AverageCalculator {
public:
    static double mark_avg(const Student& student);
};

class Student {
private:
    string name;
    double marks[3];

public:
    void get_data() {
        cout << "Enter student's name: ";
        cin >> name;

        for (int i = 0; i < 3; i++) {
            cout << "Enter mark " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void display() {
        cout << "Student's name: " << name << endl;
        cout << "Average marks: " << AverageCalculator::mark_avg(*this) << endl;
    }

    friend class AverageCalculator;
};

double AverageCalculator::mark_avg(const Student& student) {
    double sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += student.marks[i];
    }
    return sum / 3;
}

int main() {
    Student student;
    student.get_data();
    student.display();

    return 0;
}