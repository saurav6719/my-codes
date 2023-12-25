#include<iostream>
#include<vector>
using namespace std;
int f(vector<int> &input){
    if(input.size()==1) return 0; //in a single element array the first element would be minimum
    // in a sorted non rotated array first elemnt will be minimum
    int lo=0; 
    int hi = input.size()-1;
    if(input[lo] < input[hi]) return 0; //normal sorted array
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(input[mid] > input [mid+1]){
            return mid+1;
        }
        if(input[mid] < input [mid-1]){
            return mid;
        }
        if(input[mid] > input[lo]){
            lo = mid +1;
        }
        if(input[mid] < input[lo]){
            hi = mid -1;
        }
    }
    return -1;

}
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
using namespace std;
int main(){
    vector<int> input;
    
    int n=7;
    cout<<"enter all "<<n<< " values of array" <<endl;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        input.push_back(x);
    }
    int min=f(input);
    int target;
    cout<<"enter target"<<endl;
    cin>>target;
    if(binarySearch(input,target,min,0) != -1){
        cout<<"the element is present at "<<binarySearch(input,target,min,0)<<"th position"<<endl;
    }
    else if(binarySearch(input,target,input.size()-1,min) != -1){
        cout<<"the element is present at "<<binarySearch(input,target,input.size()-1,min)<<"th position"<<endl;
    }
    else{
        cout<<-1;
    }

    return 0;
}
