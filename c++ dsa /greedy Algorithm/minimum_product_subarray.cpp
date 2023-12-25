#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minProduct(vector<int> &arr){
    int cn= 0;
    int cp =0;
    int cz =0;
    int prod_pos = 1;
    int prod_neg = 1;
    int largestNegative = INT_MIN;
    for(int i = 0; i< arr.size(); i++){
        if(arr[i]<0){
            cn++;
            prod_neg *= arr[i];
            largestNegative = max(largestNegative, arr[i]);
        }
        if(arr[i] == 0) cz++;
        if(arr[i]>0){
            cp++;
            prod_pos *= arr[i];
        }

    }
    if(cn == 0){
        if(cz >0){
            return 0;
        }
        else{
            auto x = min_element(arr.begin(), arr.end());
            return *x;
        }
    }
    else{
        if(cn % 2 ==0 ){
            return (prod_pos) * (prod_neg) / largestNegative;
        }
        else{
            return prod_pos * prod_neg;
        }
    }

}
int main(){
    vector<int> v; 
    v.push_back(-1);
    v.push_back(-2);
    v.push_back(-4);
    v.push_back(5);
    v.push_back(3);
    cout<<minProduct(v)<<endl;
    return 0;
}