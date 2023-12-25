#include<iostream>
#include<vector>
using namespace std;
int f(vector<int> &input , int target){
    int lo =0; 
    int hi = input.size()-1;
    while(lo<=hi){
        if(input[lo] == input[hi]){
        hi--;       
        }
        else{
            break;
        }
    }
    while(lo<=hi){
        int mid = (lo + hi ) / 2;
        if(target == input[mid]) return mid;
        if(input[mid] > input[lo]){
            if(target >= input[lo] and target <= input[mid] ){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        else{
            if(target <= input[hi] and target >= input[mid] ){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
    }
    return -1;

}
int main(){
    vector<int> input;
    
    int n=7;
    cout<<"enter all "<<n<< " values of array" <<endl;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        input.push_back(x);
    }
    int target;
    cout<<"enter target"<<endl;
    cin>>target;
    if(f(input,target) != -1 ){
        cout<<"your target element is present"<<endl;

    }
    else{
        cout<<"your target element is not present"<<endl;
    }
}