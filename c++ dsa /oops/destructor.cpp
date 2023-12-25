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
    ~student(){
        cout<<"destructor called"<<endl;
    }
};
int main(){
    
    student s2;
   
    return 0;
}
