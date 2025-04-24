#include<iostream>
using namespace std;
int print( int arr[], int n , int index){
    //base case
    if(index == n ) {
        
        return INT_MIN;
    }
    return max(arr[index] , print(arr,n,index+1));
}
int main(){              
    int arr[] = {1,2,31,4,5};
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<print(arr, n, 0);
    return 0;
}