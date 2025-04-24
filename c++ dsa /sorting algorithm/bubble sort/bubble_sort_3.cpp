#include <iostream>
using namespace std;
int main(){
    int arr[]={5,0,1,2,0,0,4,0,3};
    int n=9;
    for(int i=0; i<n-1; i++){ // n-1passes
        bool flag= true;
        for(int j=0;j<n-i-1;j++){  // don't traverse last element 
            
                if(arr[j]==0){
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