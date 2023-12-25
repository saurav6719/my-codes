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
int inversion(vector<int> &a, vector<int> &b){
    int count =0;
    int i =0;
    int j=0;
    while(i<a.size() and j<b.size()){
        if(a[i] > b[j]){
            count += (a.size() - i);
        }
        else{
        i++;
        }
    }
    return count;
    

}
int merge_sort(vector<int> &v){
    int count =0;
    int n = v.size();
    // basse case
    if(n == 1) return 0;

    // divide into two vectors

    int n1= n/2;
    int n2= n - n/2;
     
    vector<int> v1(n1);
    vector<int> v2(n2);

    for(int i =0; i<n1; i++){
        v1[i] = v[i];
    }
    for(int i =0; i<n2; i++){
        v2[i] = v[i+n1];
    }

    // recursion

    count += merge_sort(v1);
    count += merge_sort(v2);

    count += inversion(v1,v2);

    // merge sorted array

    merge(v1,v2,v);
    return count;
}
int main(){
    int arr[] = {8,6,1,4,2,5,3,7};
    int n = 8;
    vector<int> v(arr, arr+n);
    merge_sort(v);
    cout<<merge_sort(v);
    return 0;
}