#include <iostream>
using namespace std;
int sod(int n){
    if (n>=0 and n<=9){
        return n;
    }
    return (n%10) + sod(n/10);
}
int main(){
    cout<<sod(124);
    return 0;
}

// time complexity O(d) d is the number of digits 
// space complexity O(d) d is te number of digits

