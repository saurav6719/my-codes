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
void pushAtIndex(stack<int> &st, int index, int val){
    stack<int> temp;
    while(st.size() > index){     
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    
    while(temp.size()){  
        st.push(temp.top());
        temp.pop();
    }
    return;
}

int main(){
    stack<int> st;
    
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    pushAtIndex(st,2,110);
    print(st);

    
    return 0;
}