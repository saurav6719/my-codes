#include<iostream>
#include<vector>
using namespace std;
#define int long long

struct node{
    int sum;
    int prefixmax;
    int suffixmax;
    int maxsegmentsum;
};
vector<node> st;
void buildTree(int arr[], int i, int lo, int hi){
    if(lo==hi){
        st[i].sum = arr[lo];
        st[i].prefixmax = arr[lo];
        st[i].suffixmax = arr[lo];
        st[i].maxsegmentsum = arr[lo];
        return;
    }


    int mid = lo + (hi-lo)/2;
    buildTree(arr,2*i+1,lo,mid);
    buildTree(arr,2*i+2,mid+1,hi);
    st[i].sum = (st[2*i+1].sum + st[2*i+2].sum);
    st[i].prefixmax = max(st[2*i+1].prefixmax , st[2*i+1].sum + st[2*i+2].prefixmax);
    st[i].suffixmax = max(st[2*i+2].suffixmax , st[2*i+2].sum + st[2*i+1].suffixmax);
    st[i].maxsegmentsum = max(st[2*i+1].maxsegmentsum , max(st[2*i+2].maxsegmentsum , st[2*i+1].suffixmax + st[2*i+2].prefixmax));
}

void update(int arr[], int i, int lo, int hi, int idx, int value){
    arr[idx] = value; // updating in original array
    if(idx == lo and idx == hi){
        st[i].sum = value;
        st[i].prefixmax = value;
        st[i].suffixmax = value;
        st[i].maxsegmentsum = value;
        return;
    }
    int mid = lo+(hi-lo)/2;
    if(mid >= idx) update(arr,2*i+1,lo,mid,idx,value);
    if(mid < idx) update(arr,2*i+2,mid+1,hi,idx,value);
    st[i].sum = (st[2*i+1].sum + st[2*i+2].sum);
    st[i].prefixmax = max(st[2*i+1].prefixmax , st[2*i+1].sum + st[2*i+2].prefixmax);
    st[i].suffixmax = max(st[2*i+2].suffixmax , st[2*i+2].sum + st[2*i+1].suffixmax);
    st[i].maxsegmentsum = max(st[2*i+1].maxsegmentsum , max(st[2*i+2].maxsegmentsum , st[2*i+1].suffixmax + st[2*i+2].prefixmax));
}


signed main(){
    int n,m;
    cin>>n>>m;

    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    st.resize(4*n);
    buildTree(arr,0,0,n-1);

    int xx = st[0].maxsegmentsum;
    if(xx<0) xx= 0;
    cout<<xx<<endl;
    while(m--){
        int idx;
        int val;
        cin>>idx>>val;
        update(arr, 0,0,n-1,idx,val);
        int xx = st[0].maxsegmentsum;
        if(xx<0) xx= 0;
        cout<<xx<<endl;
    }
    return 0;
}