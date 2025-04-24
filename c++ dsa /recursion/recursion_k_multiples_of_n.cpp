#include <iostream>
using namespace std;
void f(int num, int k){
    // base case
    if(k == 0) return ;
    //assumption f works perfectly for k-1
    f(num , k-1);
    //self work
    cout << (num * k)<<" ";
}
int main(){
    f(3,5);

    return 0;
}