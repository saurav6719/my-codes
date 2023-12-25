#include<iostream>
using namespace std;
class fraction{
    private:
    int numerator;
    int denominator;
    public:
    fraction(int num,int deno){
        numerator=num;
        denominator=deno;

    }
    void print(){
        cout<<this->numerator<<" / "<<this->denominator<<endl;
    }
    void simplified_fraction(){
        int gcd=1;
        int j=min(numerator,denominator);
        for(int i=1;i<=j;i++){
            if(numerator % i == 0 and denominator % i == 0){
                gcd=i;
            }
        }
        numerator = numerator / gcd;
        denominator = denominator / gcd;
        return;
    }
    bool operator==(fraction &f){
        simplified_fraction();
        f.simplified_fraction();
        if(numerator == f.numerator and denominator == f.denominator) return true;
        else return false;
    }

    
};
int main(){
    fraction f1(10,2);
    fraction f2(20,4);
    cout << (f1 == f2);
    

    return 0;
}