#include<iostream>
using namespace std;
int mountain_peak(vector<int> &input){
    int ans = -1;
    int lo =0;
    int hi = input.size()-1;
    while(lo <= hi){
        int mid = lo +(hi - lo) /  2;

        if(input[mid] > input[mid-1]){
            ans = max(mid , ans);
            lo = mid + 1;

        }
        else{
            
            hi = mid - 1;
        }
    }
    return ans;


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
    cout<<mountain_peak(input);
    return 0;

}