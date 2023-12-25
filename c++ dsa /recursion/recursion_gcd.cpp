#include <iostream>
using namespace std;
int gcd(int n, int m){ // n<m
    //base case
    if(m  == 0) return n;
    return gcd(min(n, m) , ((max(m,n))%(min(m,n))));

}
int main(){
    cout<<   gcd(90,45);
    return 0;
}