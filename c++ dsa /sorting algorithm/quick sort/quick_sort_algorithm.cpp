#include<iostream>
using namespace std;
int partition(int arr[], int si, int ei){
    int pivotElement = arr[si];
    int count = 0;
    for(int i =si+1; i<=ei ;i++){
        if(arr[i] <= pivotElement) count++;
    }
    int pivotIndex = si + count;
    swap(arr[pivotIndex], arr[si]);
    int i = si;
    int j = ei;
    while(i<=j){
        if(arr[i]<=pivotElement) i++;
        if(arr[j]>pivotElement) j--;
        else if(arr[i]> pivotElement and arr[j]< pivotElement){
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int si, int ei){
    //base case
    if(si>=ei) return;
    int pi = partition(arr,si,ei);
    quickSort(arr,si,pi-1);
    quickSort(arr,pi+1,ei);

}
int main(){

    int arr[]={5,1,8,2,7,6,3,4};
    int n = sizeof(arr)/ sizeof(arr[0]);
    for(int i =0; i< n ;i++){
        cout<<arr[i]<<" ";
    }
    
    quickSort(arr,0,n-1);
    cout<<endl;
    
    for(int i =0; i< n ;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}