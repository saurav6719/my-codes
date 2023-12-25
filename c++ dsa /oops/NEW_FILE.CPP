#include<iostream>
using namespace std;
class student{
    public:
    string name;
    int age;
    int rollno;
    void f(){
        cout<<this->age<<" "<<this->name<<" "<<this->rollno<<endl;
    }
};
int main(){
    student s1;
    s1.age = 15;
    s1.name = "kshitij";
    s1.rollno = 10;
    s1.f();

    return 0;
}