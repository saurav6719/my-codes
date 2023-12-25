#include<iostream>
using namespace std;

int main(){
    int arr[] = {12,3,1,6,18,61,61,61,16,4,3,61,18};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = 0;
    int count = 0;
    int max_ele = INT_MIN;
    for(int i = 0; i<n ;i++){
        if(arr[i] > max_ele){
            max_ele = arr[i];
            count = 1;
        }
        else if(arr[i] == max_ele) {
            count++;
        }
        else{
            count = 0;
        }
        ans = max(ans,count);
    }
    cout<<ans;
    return 0;
}