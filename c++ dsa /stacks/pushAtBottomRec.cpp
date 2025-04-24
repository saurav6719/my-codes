#include<iostream>
#include<stack>
using namespace std;
void print(stack <int>&st){
    while(st.size()){
        cout<<st.top()<<" ";   
        st.pop();
    }
    cout<<endl;
    return;
}

void pushAtBottomRec(stack<int> &st, int val){
    if(st.size()==0){
        st.push(val);
        return;
    }
    int x = st.top();
    st.pop();
    pushAtBottomRec(st,val);
    st.push(x);
}

int main(){
    stack<int> st;
    stack<int> temp;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    pushAtBottomRec(st,110);
    print(st);
}