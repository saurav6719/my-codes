#include <iostream>
using namespace std;
void f(int *arr, int n,int i, int sum, vector<int> &result){
    //base case 
    if(i == n){
        result.push_back(sum);
        return;
    }
    f(arr,n,i+1,sum + arr[i],result);
    f(arr,n,i+1,sum ,result);

    
}
int main(){
    
    int arr[]={2,3,4};
    vector <int> result;
    f(arr , 3, 0, 0, result);
    for(int i=0 ; i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;

}