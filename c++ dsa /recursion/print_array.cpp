#include<iostream>
using namespace std;
void ans( int arr[], int n , int index){
    //base case
    if(index == n ) return;
    cout<<arr[index]<<" ";
    ans(arr, n, index+1);
}
int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/ sizeof(arr[0]);
    ans(arr, n, 0);
    return 0;

}