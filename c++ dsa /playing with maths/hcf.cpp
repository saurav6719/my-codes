#include<iostream>
using namespace std;
int hcf(int num1,int num2){   //num1 > num2
    while(num2 != 0){
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}
int main(){
    int n1,n2;
    cin>>n1>>n2;
    cout<<hcf(n1,n2);    // n1>n2
    return 0;
}