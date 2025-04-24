#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void display(queue<int> &q){
    int n = q.size();
    for(int i = 0; i< n ; i++){
        int a = q.front();
        cout<<a<<" ";
        q.pop();
        q.push(a);
    }
    cout<<endl;
}
void reverse(int k, queue<int> &q){
    stack<int> st;
    int n = q.size();
    for(int i = 1; i<=k ; i++){
        int a = q.front();
        st.push(a);
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    for(int i = 1; i<=n-k; i++){
        int a = q.front();
        q.push(a);
        q.pop();
    }
}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    display(q);
    reverse(2,q);
    display(q);
    return 0;
}