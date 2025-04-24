#include<iostream>
using namespace std;
int armstrong(int n, int m){
    if (n == 0) return n ;
    
   
    int result =  pow((n%10), m) + armstrong(n/10,m);
   
    
    return result;

}
int main(){
    int  n;
    cout<<"enter the number"<<endl;
    cin>>n;
    int n_copy = n;
    int m=0 ;   //m = no of digits in n
    while(n_copy !=0){
        n_copy /= 10;
        m++;
    }
    if (armstrong(n,m) == n )
    {
      cout<<"the given number is a armstrong number "<<endl;
    }
    else{
        cout<<"the given number is not an armstrong number"<<endl;
    }

    
    return 0;
}