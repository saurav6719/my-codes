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
using namespace std;
int main(){
    vector<int> input;
    
    int n=1;
    cout<<"enter all "<<n<< " values of array" <<endl;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        input.push_back(x);
    }
    cout<<f(input);
    return 0;
}