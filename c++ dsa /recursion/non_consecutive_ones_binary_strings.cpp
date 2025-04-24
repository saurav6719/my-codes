#include<iostream>
using namespace std;
int ans(int n){
    //base case
    if(n==1 or n==2) return n+1;
    return ans(n-1) + ans(n-2);
}
int main(){
    cout<<ans(5);
    return 0;
}