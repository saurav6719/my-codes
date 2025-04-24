#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &a,vector<int> &b,vector<int> &res){
    int i =0; //a
    int j=0;  //b
    int k =0;  //res
    while(i<a.size() and j<b.size()){
        if(a[i] <= b[j]){
            res[k] = a[i];
            k++;
            i++;
        }
        else{
            res[k] = b[j];
            k++;
            j++;
        }
    }
    if(i == a.size()){
        while(j<b.size()){
            res[k] = b[j];
            k++;
            j++;
        }
    }
    if(j == b.size()){
        while(i<a.size()){
            res[k] = a[i];
            k++;
            i++;
        }
    }
}
int main(){
    int arr[]= {1,2,3};
    int n1 = sizeof(arr)/ sizeof(arr[0]);
    vector<int> a(arr,arr+n1);
    int brr[]= {2,5,6};
    int n2 = sizeof(brr)/ sizeof(brr[0]);
    vector<int> b(brr,brr+n2);
    vector<int> res(n1+n2);
    merge(a,b,res);
    for(int i =0;i<n1+n2;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}