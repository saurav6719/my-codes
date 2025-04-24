#include<iostream>
using namespace std;
class student{
    public:

    int age;
    char *name;

    student(student &s){
        this->name = new char [strlen(s.name)+1];
        strcpy(this->name, s.name);
    }
    
};
int main(){
    return 0;
}