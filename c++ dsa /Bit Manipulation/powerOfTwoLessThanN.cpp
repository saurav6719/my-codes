#include<iostream>
using namespace std;


int main(){
    int n = 100;
    int result;
    n = n | n>>1;
    n = n | n>>2;
    n = n | n>>4;
    n = n | n>>8;
    n = n | n>>16;

    result = (n + 1) / 2;
    cout<<result;
    return 0;
}