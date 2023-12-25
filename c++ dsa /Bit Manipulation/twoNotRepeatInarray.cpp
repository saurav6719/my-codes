#include<iostream>
using namespace std;
int main(){
    int arr[] = {2,1,3,2,1,5,5,56,3,17};
    int n = sizeof(arr) / sizeof(arr[0]);
    int firstXOR = 0;
    for(int i = 0; i< n ; i++){
        firstXOR ^= arr[i];
    }
    int k = 0; // for checking konsa bit set hai xor me 
    while(true){
        if((firstXOR & 1) == 1){
            break;
        }
        else k++;
    }
    int secondXOR = 0;
    for(int i = 0; i< n ; i++){
        int num = arr[i];
        int num_copy = num;
        num = num >> k;
        if((num & 1) == 1){
            secondXOR ^= num_copy;
        }
    }
    
    int first = secondXOR;
    int second = firstXOR ^ first;
    
    cout<<first<<" "<<second<<endl;
    return 0;
}