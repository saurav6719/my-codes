#include<iostream>
#include<vector>
using namespace std;
int binarySearch(int v[],int target){
    int low=0;
    int n=9;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(v[mid]==target) return mid;
        else if(v[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
    return -1;
}
int main(){
    int v[]={2,3,5,7,11,14,16,19,22};
    
    int target=10;
    if(binarySearch(v,target)!=-1){
        cout<<"the target element is present at "<<binarySearch(v,target)+1<<"th position"<<endl;
    }
    else{
        cout<<"the target element is not present in the given vector"<<endl;
    }
    return 0;
}