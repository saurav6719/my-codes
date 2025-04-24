#include<iostream>
using namespace std;
//parent class
class vehicle {
    public:
    string color;
    private:
    int maxSpeed;
    protected:
    int numTyres;
};
class car : public vehicle{
    public:
    int numGears;
    void print(){
        cout<<"number of tyres: "<<numTyres<<endl;
        cout<<"colour is :"<<color<<endl;
        cout<<"number of gears :"<<numGears<<endl;
        
    }

};
int main(){
    car c1;
    c1.numGears;
    return 0;

}
