#include <iostream>
using namespace std;
class PersonalDetails {
public:
    string name;
    char surname;
    double totalMarks;
    char gender;
    char result;

    void getInput() {
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your surname (single character): ";
        cin >> surname;
        cout << "Enter total marks: ";
        cin >> totalMarks;
        cout << "Enter gender (M/F): ";
        cin >> gender;
        cout << "Enter result (P/F): ";
        cin >> result;
    }

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Total Marks: " << totalMarks << endl;
        cout << "Gender: " << gender << endl;
        cout << "Result: " << result << endl;
    }
};

int main() {
    using namespace std;
    PersonalDetails details;
    details.getInput();
    details.displayDetails();
    return 0;
}