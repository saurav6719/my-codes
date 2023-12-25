#include<iostream>
using namespace std;
class student{
    int age;
    public:
    int getAge(){
        return age;
    }
    void setAge(int a){
        age=a;
    }
};
int main(){
    student s1;
    student *s2 = new student;
    s2->setAge(40);
    s1.setAge(23);
    cout<<s1.getAge()<<" "<<s2->getAge();
    return 0;
}