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
    void add(fraction &f){
        int lcm=denominator * f.denominator;
        int x = lcm / denominator;
        int y = lcm / f.denominator;
        int z = x * numerator + (y * (f.numerator)) ;
        numerator = z;
        denominator = lcm;
        simplified_fraction();
        
        return;
    }
    
};
int main(){
    fraction f1(10,2);
    fraction f2(20,4);
    f1.add(f2);
    f1.print();
    f2.print();
    

    return 0;
}