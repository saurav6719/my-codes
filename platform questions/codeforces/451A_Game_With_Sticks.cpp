#include<iostream>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int x = min(a,b);
    if(x % 2 == 0) cout<<"Malvika";
    else cout<<"Akshat";
    return 0;
}