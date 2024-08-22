#include<iostream>
#include<vector>
using namespace std;
vector<int> st;
vector<int> lazy;
void buildTree(int arr[], int i, int lo, int hi){
    if(lo==hi){
        st[i] = arr[lo];
        return;
    }
    int mid = lo + (hi-lo)/2;
    buildTree(arr,2*i+1,lo,mid);
    buildTree(arr,2*i+2,mid+1,hi);
    st[i] = (st[2*i+1] + st[2*i+2]);
}

void update(int i, int lo, int hi, int l, int r, int val){

    //before doing any thing do lazy updates 
    if(lazy[i] != 0){
        int range = hi - lo +1;
        st[i] += (range * lazy[i]);
        // send lazy to left and right if not leaf 
        if(lo != hi){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        //set lazy to zero 
        lazy[i] = 0;

    }

    //out of range
    if(l>hi or r<lo) return;

    //overlapping

    if(lo>=l and hi <=r) { // update in whole range
        int range = hi - lo + 1;
        st[i] +=( range * val);
        // now give lazy to left and right if not leaf 
        if(lo != hi){
            lazy[2*i+1] += val;
            lazy[2*i+2] += val;
        }
        return;
    }
    
    // dono call lagao 
    int mid = (lo+hi) / 2;
    update(2*i+1, lo, mid,l, r, val );
    update(2*i+2, mid+1, hi,l, r, val );
    st[i] = st[2*i+1] + st[2*i+2];
}

int getSum(int i, int lo, int hi, int l, int r){ // we are finding max in l to r

    //before doing anything check for lazy pendings 
    if(lazy[i] != 0){
        int range = hi - lo +1;
        st[i] += range * lazy[i];
        // send lazy to left and right if not leaf 
        if(lo != hi){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        //set lazy to zero 
        lazy[i] = 0;
    }
    // out of range 
    if(l>hi or r<lo) return 0;
    //subset
    if(lo>=l and hi <=r) return st[i];
    int mid = lo + (hi-lo)/2;
    int left = getSum(2*i+1,lo,mid,l,r);
    int right = getSum(2*i+2,mid+1,hi,l,r);
    return left + right;
}


int main(){
    int arr[] = {1,3,5};
    int n = sizeof(arr)/4;
    st.resize(4*n);
    lazy.resize(4*n, 0);
    buildTree(arr,0,0,n-1);
    cout<<getSum(0,0,n-1,0,2)<<endl;
    update(0, 0, n-1, 1, 2, 50);
    cout<<getSum(0,0,n-1,0,2)<<endl;
    return 0;
}