#include<iostream>
#include<algorithm>
#define mn(a,b,c)  min(a,min(b,c))
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n>=0) cout<<n;
    else{
        int answer;
        int n_copy = n * -1;
        int mod = n_copy % 10;
        int first = (n_copy / 10);
        int second =(( first / 10 ) * 10) + mod;
        answer = mn(first,second,n_copy);
        if(answer != 0) cout<<(answer* -1);
        else cout<<"0";
    }
    return 0;
}