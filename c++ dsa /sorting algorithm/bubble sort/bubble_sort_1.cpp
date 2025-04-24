#include<iostream>
using namespace std;
int main(){
    int arr[]={5,4,10,21,3};
    int n=5;
    
    
    for(int i=0; i<n-1; i++){ // n-1passes
        bool flag= true;
        for(int j=0;j<n-i-1;j++){  // don't traverse last element 
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = false;
            }
            

        }

        if(flag == true ){ /// swap nhi hua array mtb sorted hai already 
            break;
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}