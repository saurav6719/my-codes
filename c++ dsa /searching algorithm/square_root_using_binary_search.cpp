#include<iostream>
using namespace std;
int squareRoot(int n){
    int low=0;
    int ans=-1;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mid*mid <=n){
            ans = mid;
            low= mid +1;

        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
int main(){
    cout<<squareRoot(100);
    return 0;
}