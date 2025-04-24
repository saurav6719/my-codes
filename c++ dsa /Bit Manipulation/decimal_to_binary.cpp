#include<iostream>
using namespace std;

string dtb(int n){
    string s ="";
    while(n>1){
        if(n%2 ==0){
            s = '0' + s;
        }
        else{
            s = '1' + s;
        }
        n/=2;
    }
    if(n==1) s = '1' + s;
    else s = '0' + s;
    return s;

}
int main(){
    int n = 14;
    cout<<dtb(n);
    return 0;
}