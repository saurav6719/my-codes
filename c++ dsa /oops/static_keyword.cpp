#include<iostream>
using namespace std;
class student{
    public:
    int age;
    int rollNumber;
    static int totalStudents ;
    
    student (){
        totalStudents++;
    }

};
int student :: totalStudents = 0;
int main(){
    student s1,s2,s3,s4,s5;
    cout<<s1.totalStudents<<endl;
    


    return 0;
}