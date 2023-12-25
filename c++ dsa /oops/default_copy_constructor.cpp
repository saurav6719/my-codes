#include<iostream>
using namespace std;
class student{
    public:

    int age;
    string *name;
    
};
int main(){
    string name="saurav";
    student s1;
    s1.age = 15;
    s1.name = &name;
    cout<<*(s1.name)<<endl;
    // default copy constructor
    student s2(s1);
    name[0] = 'g';
    cout<<*(s1.name)<<endl; //gaurav
    cout<<*(s2.name)<<endl; //gaurav 

    //default copy constructor do shallow copy 
    


    return 0;
}