#include<iostream>
using namespace std;
class vehicle{
    int maxSpeed;
    protected:
    int numGears;
    public:
    string color;
    // vehicle(){
    //     cout<<"vehicle default constructor called"<<endl;
    // }
    vehicle(int z){
        cout<<"vehicle parametrised constructor called " <<z <<endl;
    }
    ~vehicle(){
        cout<<"vehicle destructor"<<endl;
    }

};
class car : public vehicle{
    public:
    car(int x, int y) : vehicle(5){
        cout<<"car default constructor called"<<endl;
    }
    ~car(){
        cout<<"car destructor"<<endl;
    }
};
class hondaCity : public car{
    public:
    hondaCity() : car(2,3){
        cout<<"hondacity parametrised constructor called"<<endl;
    }
    ~hondaCity(){
        cout<<"hondacity destructor"<<endl;
    }
};
int main(){
    hondaCity h1;
    return 0;
}