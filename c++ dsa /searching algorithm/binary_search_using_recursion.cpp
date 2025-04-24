#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int>&v,int target,int high,int low){
    if(low>high) return -1;
    int mid=(low+high)/2;
    //base case
    if(v[mid]==target) return mid;
    else if(v[mid]<target){
        return binarySearch(v,target,high,mid+1);
    }
    else{
        return binarySearch(v,target,mid-1,low);
    }
}
int main(){
    vector<int> v;
    int n=5;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int target;
    cin>>target;
    cout<<binarySearch(v,target,n-1,0);
    return 0;
}