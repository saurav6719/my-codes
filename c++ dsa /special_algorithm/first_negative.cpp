#include<iostream>
using namespace std;
int main(){
    int arr[] = {2,-3,4,4,-7,-1,4,-2,6};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int k = 3;
    int brr[n-k+1];
    int first_negative;
    for(int i = 0; i<k ; i++){
        if(arr[i]<0){
            brr[0] = arr[i];
            first_negative = i;
            break;
        }
    }
    int i = 1;
    int j = k;

    while(j<n){
        if(i <= first_negative) brr[i] = arr[first_negative];
        else{
            for(int p = i ;p<k+i; p++){
                if(arr[p] < 0) {
                    first_negative = p;
                    brr[i] = arr[first_negative];
                    break;
                }
            }
        }
        i++;
        j++;
    }
    for(int i = 0; i< n-k+1 ; i++){
        cout<<brr[i]<<" ";
    }
}