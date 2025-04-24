#include <iostream>
using namespace std;
bool f(int n, int x, int *arr, int i ){
    //base case 
    if(i == n) return false;
    return (arr[i] == x ) or f(n,x,arr,i+1) ;

}
int main(){
    int arr[]={2,3,5,5};
    int n =4;
    int x= 4;
    cout<<f(n,4,arr,0);
    return 0;
}