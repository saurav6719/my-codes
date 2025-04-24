#include<iostream>
#include<stack>
using namespace std;
void recur(stack<int> st){
    if(st.size() == 1){
        cout<< st.top()<<" ";
        return;
    }
    int x = st.top();
    st.pop();
    recur(st);
    cout<<x<<" ";
}
int main(){
    stack<int> st;
    stack<int> temp;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    recur(st);
    
    
}