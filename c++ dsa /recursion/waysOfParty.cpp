#include<iostream>
using namespace std;
int rec(int n){
    //base  case
    if(n==1 or n==2) return n;
    return rec(n-1) + (n-1) * rec(n-2);
}
int main(){
    int n= 4;
    cout<<rec(n);
    return 0;
}