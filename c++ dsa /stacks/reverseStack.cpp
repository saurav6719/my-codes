#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
    stack<int> gt;
    stack<int> temp;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    while(st.size()){
        cout<<"elements in st "<<st.top()<<" ";
        int x = st.top();
        temp.push(x);
        st.pop();
    }
    cout<<endl;
    while(temp.size()){
        cout<<"elements in temp "<<temp.top()<<" ";
        int x = temp.top();
        gt.push(x);
        temp.pop();
    }
    cout<<endl;
    
    while(gt.size()){
        cout<<"elements in gt "<<gt.top()<<" ";
        int x = gt.top();
        st.push(x);
        gt.pop();
    }
    cout<<endl;
    while(st.size()){
        cout<<"elements in st "<< st.top()<<" ";
        
        st.pop();
    }

    return 0;
}
