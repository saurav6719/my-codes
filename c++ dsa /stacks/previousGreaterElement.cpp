#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[]= {3,1,2,5,4,6,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(n);
    stack<int> st;
    v[0] = -1;
    st.push(arr[0]);
    for(int i = 1; i< n; i++){
        while((st.size()!= 0) and (st.top()< arr[i])) st.pop();
        if(st.empty()) v[i] =-1;
        else v[i] = st.top();
        st.push(arr[i]);
    }
    for(int i =0 ;i< n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i =0 ;i< n ;i++){
        cout<<v[i]<<" ";
    }

    return 0;
}