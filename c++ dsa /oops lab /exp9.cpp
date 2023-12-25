#include <iostream>
#include <cstring>
using namespace std;
//9.	WAP to perform string operations using operator overloading in C++
// i. = String Copy 
// ii. ==,<,> Equality
// iii. + Concatenation

class MyString {
private:
    char* str;

public:
    MyString(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    MyString operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    bool operator==(const MyString& other) const {
        return strcmp(str, other.str) == 0;
    }

    bool operator<(const MyString& other) const {
        return strcmp(str, other.str) < 0;
    }

    bool operator>(const MyString& other) const {
        return strcmp(str, other.str) > 0;
    }

    MyString operator+(const MyString& other) const {
        char* newStr = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(newStr, str);
        strcat(newStr, other.str);
        MyString result(newStr);
        delete[] newStr;
        return result;
    }

    const char* c_str() const {
        return str;
    }

    ~MyString() {
        delete[] str;
    }
};

int main() {
    MyString str1("Hello");
    MyString str2("World");
    MyString str3 = str1 + str2;

    cout << "str1: " << str1.c_str() << endl;
    cout << "str2: " << str2.c_str() << endl;
    cout << "str3 (Concatenation of str1 and str2): " << str3.c_str() << endl;

    if (str1 == str2) {
        cout << "str1 is equal to str2." << endl;
    } else {
        cout << "str1 is not equal to str2." << endl;
    }

    if (str1 < str2) {
        cout << "str1 is less than str2." << endl;
    } else {
        cout << "str1 is not less than str2." << endl;
    }

    if (str1 > str2) {
        cout << "str1 is greater than str2." << endl;
    } else {
        cout << "str1 is not greater than str2." << endl;
    }

    return 0;
}