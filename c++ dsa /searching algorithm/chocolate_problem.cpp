#include <iostream>
#include <vector>
using namespace std;
bool canDistribute(vector<int> &arr, int s,int mid){
    int current_sum = 0;
    int students_required = 1;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > mid) return false;
        if((current_sum + arr[i]) > mid) {
            students_required ++;
            current_sum = arr[i];
            if(students_required > s) return false;
            
        }
        else current_sum += arr[i];
        
    }
    return true;
}
int distributeChoco(vector<int> &arr, int s){
    int lo =arr[0];
    int hi = 0;
    
    for(int i =0; i<arr.size(); i++){
        hi += arr[i];
    }
    int ans=-1;
    while(lo<=hi){
        int mid = lo +(hi-lo)/2;
        if(canDistribute(arr,s,mid)){
            ans = mid;
            hi = mid -1;
        }
        else{
            lo = mid + 1;

        }
    }
    return ans;
}
int main(){
    int students = 3;
    int boxes= 3;


    vector<int> v;
    for(int i =0; i<boxes ;i++){
        int x;
        cin>>x;
        v.push_back(x);

    }
    cout<<distributeChoco(v,students)<<endl;

    return 0;
}