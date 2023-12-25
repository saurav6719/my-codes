#include<iostream>
#include<vector>
using namespace std;
bool canPlace(vector<int> &arr , int s, int mid){
    int studentsRequired = 1;
    int lastPlaced = arr[0];
    for(int i =1; i<arr.size() ; i++){
        if(arr[i] - lastPlaced >= mid){
            studentsRequired ++;
            lastPlaced = arr[i];
            if(studentsRequired == s) return true;
        }
    }
    return false;
}
int race(vector<int> &arr , int s){
    int n = arr.size();
    int lo =1; // minimum distance between two players will be 1 
    int hi = arr[n-1] - arr[0]; // maximum distance between two players
    int ans = -1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(canPlace(arr,s,mid)){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid -1;
        }

    }
    return ans;
}
int main(){
    int students = 3;
    int no_of_stops = 5;
    vector<int> v;
    for(int i =0; i<no_of_stops ;i++){
        int x;
        cin>>x;
        v.push_back(x);

    }
    cout<<race(v,students)<<endl;
    return 0;

}