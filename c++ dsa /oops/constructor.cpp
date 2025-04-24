#include<iostream>
using namespace std;
class student{
    public:
    int age;
    student(){
        cout<<"constructor called"<<endl;
    }
    student(int a){
        cout<<"parametrsied constructor called "<<endl;
        age=a;
    }
};
int main(){
    student s1(23);
    student s2;
    cout<<s1.age;
    return 0;
}
