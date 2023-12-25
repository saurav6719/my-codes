#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[]= {100,80,60,70,60,75,85};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(n);
    vector<int> v2(n);
    stack<int> st;
    v[0] = -1;
    st.push(0);
    for(int i = 1; i< n; i++){
        while((st.size()!= 0) and (arr[st.top()]< arr[i])) st.pop();
        if(st.empty()) v[i] =-1;
        else v[i] = st.top();
        st.push(i);
    }
    for(int i =0 ;i< n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i =0 ;i< n ;i++){
        if(v[i] == -1) v2[i] = 1;
        else v2[i] = i - v[i];
    }
    for(int i =0 ;i< n ;i++){
        cout<<v2[i]<<" ";
    }
    
    
}