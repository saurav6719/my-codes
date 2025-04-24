#include<iostream>
using namespace std;
int partition(int arr[], int si, int ei){
    int pivotElement = arr[(si+ei)/2];
    int count = 0;
    for(int i =si; i<=ei ;i++){
        if(i == (si+ei)/2) continue;
        if(arr[i] <= pivotElement) count++;
    }
    int pivotIndex = si + count;
    swap(arr[pivotIndex], arr[(si+ei)/2]);
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

int quickSort(int arr[], int si, int ei, int k){
    //base case
    
    int pi = partition(arr,si,ei);
    if(pi == k-1) return arr[pi];
    if(pi< k-1){
        
        return quickSort(arr,pi+1,ei,k);
    }
    if(pi > k-1){
        
        return quickSort(arr,si,pi-1,k);
    }
   
    

}
int main(){

    int arr[]={5,1,8,2,7,6,3,4};
    int n = sizeof(arr)/ sizeof(arr[0]);
    for(int i =0; i< n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<quickSort(arr,0,n-1,4);
    return 0;
}