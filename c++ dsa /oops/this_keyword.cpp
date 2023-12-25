#include<iostream>
using namespace std;
class student{
    public:
    int age;
    student(int age){
        this->age=age;
    }
};
int main(){
    student s1(13);
    student s2(15);
    cout<<s1.age<<endl;
    cout<<s2.age<<endl;
    return 0;
}