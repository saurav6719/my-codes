#include<iostream>
using namespace std;
int help(int arr[], int n){
    int ans = 1;
    for(int i = 1; i<n;i++){
        int j =0;
        for(j = 0;j<i;j++){
            if(arr[i] == arr[j]){
                break;
            }
        }
        if(i==j) ans++;
    }
    return ans;
}
int main(){
    int arr[] ={1,2,3,4,3,2,1};
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<help(arr,n); 
    return 0;
}