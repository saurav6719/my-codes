#include<iostream>
using namespace std;
class student{
    public:
    int age;
    int rollno;

    student(int a, int r){
        age=a;
        rollno=r;
    }
};
int main(){
    student s1(10,100);
    student s2(s1);               //copy constructor
    cout<<s2.age<<" "<<s2.rollno;


}