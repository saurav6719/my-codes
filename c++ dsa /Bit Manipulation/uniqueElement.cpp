#include<iostream>
using namespace std;
int main(){
    int arr[] = {2,1,3,3,1,2,5};
    int n = 7;
    int result = 0;
    for(int i = 0; i<7; i++){
        result = result ^ arr[i];
    }
    cout<<result;
    
}