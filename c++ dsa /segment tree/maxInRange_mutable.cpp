#include<iostream>
#include<vector>
using namespace std;
vector<int> st;
void buildTree(int arr[], int i, int lo, int hi){
    if(lo==hi){
        st[i] = arr[lo];
        return;
    }
    int mid = lo + (hi-lo)/2;
    buildTree(arr,2*i+1,lo,mid);
    buildTree(arr,2*i+2,mid+1,hi);
    st[i] = max(st[2*i+1], st[2*i+2]);
}

void update(int arr[], int i, int lo, int hi, int idx, int value){
    arr[idx] = value; // updating in original array
    if(idx == lo and idx == hi){
        st[i] = value;
        return;
    }
    int mid = lo+(hi-lo)/2;
    if(mid >= idx) update(arr,2*i+1,lo,mid,idx,value);
    if(mid < idx) update(arr,2*i+2,mid+1,hi,idx,value);
    st[i] = max(st[2*i+1], st[2*i+2]);
}

int getMax(int i, int lo, int hi, int l, int r){ // we are finding max in l to r
    // out of range 
    if(l>hi or r<lo) return INT_MIN;
    //subset
    if(lo>=l and hi <=r) return st[i];
    int mid = lo + (hi-lo)/2;
    int left = getMax(2*i+1,lo,mid,l,r);
    int right = getMax(2*i+2,mid+1,hi,l,r);
    return max(left,right);
}


int main(){
    int arr[] = {1,4,2,8,6,4,9,3};
    int n = sizeof(arr)/4;
    st.resize(4*n);
    buildTree(arr,0,0,n-1);
    cout<<getMax(0,0,n-1,2,5)<<endl;
    update(arr,0,0,n-1,4,10);
    cout<<getMax(0,0,n-1,2,5)<<endl;
    return 0;
}