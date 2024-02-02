#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<unordered_map<int,int> > st;
unordered_map<int,int> addmap(unordered_map<int,int> &mp1, unordered_map<int,int> & mp2){
    unordered_map<int,int> ans;
    for(auto ele : mp1){
        int key = ele.first;
        int freq = ele.second;
        ans[key]+= freq;
    }
    for(auto ele : mp2){
        int key = ele.first;
        int freq = ele.second;
        ans[key]+= freq;
    }
    return ans;
}


void buildTree(int arr[], int i, int lo, int hi){
    if(lo==hi){
        st[i][arr[lo]] = 1;
        return;
    }
    int mid = lo + (hi-lo)/2;
    buildTree(arr,2*i+1,lo,mid);
    buildTree(arr,2*i+2,mid+1,hi);
    st[i] = addmap(st[2*i+1], st[2*i+2]);
}
int getFreq(int i, int lo, int hi, int l, int r, int value){ // we are finding freq of value in l to r
    // out of range 
    if(l>hi or r<lo) return 0;
    //subset
    if(lo>=l and hi <=r) return st[i][value];
    int mid = lo + (hi-lo)/2;
    int left = getFreq(2*i+1,lo,mid,l,r,value);
    int right = getFreq(2*i+2,mid+1,hi,l,r,value);
    return left + right;
}


int main(){
    int arr[] = {2,4,2,4,6,4,2,6};
    int n = sizeof(arr)/4;
    st.resize(4*n);
    buildTree(arr,0,0,n-1);
    cout<<getFreq(0,0,n-1,0,3,6)<<endl;
    return 0;
}