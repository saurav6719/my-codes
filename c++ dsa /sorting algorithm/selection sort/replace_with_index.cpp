#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[]={19,12,23,8,16};

    int n=5;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
    vector<int> copy;
    for(int i=0;i<n;i++){
        copy.push_back(arr[i]);
    }
    sort(copy.begin(),copy.end());
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(copy[i]==arr[j]){
                arr[j]=i;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }

    return 0;
}