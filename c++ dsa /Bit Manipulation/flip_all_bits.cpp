#include<iostream>
using namespace std;
int main(){
    int n = 16;
    int n_copy = n;
        n_copy = n_copy | (n_copy >> 1);
        n_copy = n_copy | (n_copy >> 2);
        n_copy = n_copy | (n_copy >> 4);
        n_copy = n_copy | (n_copy >> 8);
        n_copy = n_copy | (n_copy >> 16);
    n = n ^ n_copy;
    cout<<n;
    return 0;
}