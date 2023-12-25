#include<iostream>
#include<queue>
using namespace std;
class Stack{
public:
    queue<int> q1;
    queue<int> q2;
    void push(int val){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q2.push(val);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop(){
        q1.pop();
    }
    int size(){
        int n = 0;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
            n++;
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return n;
    }
    int top(){
        return q1.front();
    }
  
};

int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout<<st.size()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top();
    return 0;
}