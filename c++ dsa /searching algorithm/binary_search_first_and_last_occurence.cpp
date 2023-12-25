#include<iostream>
#include<vector>
using namespace std;
int firstOccurence(vector<int> &input,int target,int lo,int hi){
    int result=-1;
    int ans;
    int n=input.size();
    
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(input [mid] >=target){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    if(input[ans]==target){
        return input[ans];
    }
    return result;
}
int lastOccurence(vector<int> &input,int target,int lo,int hi){
    int result=-1;
    int ans;
    int n=input.size();
    
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(input [mid] <=target){
            ans=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    if(input[ans]==target){
        return input[ans];
    }
    return result;
    

}
int main(){
    vector<int> input;
    vector<int> result;
    int n=8;
    cout<<"enter all "<<n<< " values of array" <<endl;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        input.push_back(x);
    }
    int target;
    cout<<"enter target value"<<endl;
    cin>>target;
    result.push_back(firstOccurence(input,target,0,n-1));
    result.push_back(lastOccurence(input,target,0,n-1));
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return 0;
}