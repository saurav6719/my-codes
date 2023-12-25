#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
    stack<int> temp;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    while(st.size()){
        cout<<st.top()<<" ";
        int x = st.top();
        temp.push(x);
        st.pop();
    }
    cout<<endl;
    while(temp.size()){
        cout<<temp.top()<<" ";
        int x = temp.top();
        st.push(x);
        temp.pop();
    }
    cout<<endl;
    
    while(st.size()){
        cout<<st.top()<<" ";
        
        st.pop();
    }


    return 0;
}
