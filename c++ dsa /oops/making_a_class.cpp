#include<iostream>
#include<string>
using namespace std;
class student{
    public:
    int rollNumber;
    private :
    int age;
    string name;
    public:
    void display(student s){
        cout<<rollNumber<<" "<<age<<" "<<name<<endl;
        return;
    }
};



int main(){
    student s1;
    s1.rollNumber=10;
    s1.display(s1);
    return 0;
}