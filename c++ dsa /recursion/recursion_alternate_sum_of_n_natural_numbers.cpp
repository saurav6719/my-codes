#include <iostream>
using namespace std;
// question alternate sum upto n 
// n =5
//output 1-2+3-4+5 =3
int f(int n){
    //base case 
    if(n==0) return 0;
    //assumption f works correctly for n-1 terms 
    return f(n-1) + ((n%2==0)?(-n):n);
    
}
int main(){
    
    cout<<f(10);
    return 0;

}