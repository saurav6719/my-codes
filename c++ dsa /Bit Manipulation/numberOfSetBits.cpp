#include<iostream>
using namespace std;


int main(){
    int n = 7;
    int result = 0;
    while(n != 0){
        n = n & n-1;
        result++;
    }
    cout<<result;
    return 0;
}