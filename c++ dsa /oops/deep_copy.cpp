#include<iostream>
using namespace std;
class student{
    public:

    int age;
    string name;
    //copy constructor
    student(int age, string name){
        this->age = age;
        this->name = name;
    }
};
int main(){
    string name = "saurav";
    student s1(20 , name);
    cout<<(s1.name)<<endl;
    name[0] = 'g';
    student s2(24, name);
    cout<<(s1.name)<<endl;
    cout<<(s2.name)<<endl;

    return 0;
}