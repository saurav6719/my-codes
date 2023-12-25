#include<iostream>
using namespace std;
int main(){

    int arr[]= {7,1,2,5,8,4,9,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max_sum = INT_MIN;
    int prev_sum = 0;
    int k = 3;
    int i = 1; 
    int j = k;

    for(int a =0 ;a<k ; a++){
        prev_sum += arr[a]; 
    }

    max_sum = max(max_sum , prev_sum);

    while(j<n){
        int current_sum = 0;
        current_sum = prev_sum + arr[j] - arr[i-1];
        max_sum = max(current_sum , max_sum);
        prev_sum = current_sum;
        i++;
        j++;
    }
    
    cout<<max_sum;
    return 0;

}