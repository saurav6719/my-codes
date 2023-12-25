#include<iostream>
using namespace std;
class student{
    public:
    int age;
    const int rollNumber;
    int &x;

    student(int r, int a) : rollNumber(r) , age(a),  x(age){
    
    }
};
int main(){
    student s1(100, 15);
   
    cout<<s1.age<<endl<<s1.rollNumber<<endl<<(s1.x);
    return 0;
}