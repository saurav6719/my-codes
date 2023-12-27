#include<iostream>
using namespace std;
long long kthodd(long long k){
    long long a = -1;
    for(long long i = 1; i<=k ;i++){
        a += 2;
    }
    return a;

}
long long ktheven(long long k){
    long long a = 0;
    for(long long i = 1; i<=k ;i++){
        a += 2;
    }
    return a;
}
int main(){
    long long n,k;
    cin>>n>>k;
    if(n %2 == 0){
        if(k <= n/2){
            cout<<kthodd(k);
        }
        else{
            cout<<ktheven(k - (n/2));
        }
    }
    else{
        if(k<= (n+1) /2){
            cout<<kthodd(k);
        }
        else{
            cout<<ktheven(k - ((n+1)/2));
        }
    }
    return 0;
}