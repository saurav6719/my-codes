#include<iostream>
using namespace std;
int f(int p, int q){
    if (q==0) return 1;
    if(q%2 == 0){
        // q is even
        int result = f(p,q/2);
        return result * result; 
    }
    else{
        // q is odd
        int result = f(p,(q-1)/2);
        return p * result * result;
    }
}
int main(){
    cout<<f(2,5)<<endl<<f(2,4)<<endl<<f(2,0);
    return 0;

}