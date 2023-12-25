#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5,5,10};
    int n = sizeof(arr)/ sizeof(arr[0]);
    for(int i = 1; i<n ;i++ ){
        arr[i] += arr[i-1];
    }
    bool flag = false;
    for(int i = 0; i< n ; i++){
        flag = true;
        if(2 * arr[i] == arr[n-1]){
            cout<<"yes it can be partitioned after "<<i<<" ";
            break;
        }
        
    }
    if(!flag) cout<<"no it can't be partitioned"<<endl;
    return 0;
}