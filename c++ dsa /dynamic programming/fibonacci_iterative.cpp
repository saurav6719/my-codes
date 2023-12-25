#include<iostream>
#include<vector>
using namespace std;
vector<int> dp;
int fib(int n ){
    int i = 0;
    int a = 0;
    int b = 1;
    int c; 
    for(int i = 2 ; i<=n; i++){
        c = a+b;
        a = b;
        b = c;
    }
    return c;
    
}
int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<" ";
}