#include<iostream>
using namespace std;
void printFactors(int n){
    for(int i=1;i<sqrt(n);i++){
        if(n%i==0) cout<<i<<" ";
    }
    for(int i=sqrt(n);i>0;i--){
        if(n%i==0) cout<<n/i<<" ";
    }
}
int main(){
    printFactors(60);
    cout<<endl;
    printFactors(49);
    return 0;
}