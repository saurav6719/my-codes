#include<iostream>
#include<stack>
using namespace std;

class Queue{
    public:
    stack<int> st1;
    stack<int> st2;
    void push(int val){
        st1.push(val);
    }
    void pop(){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st2.pop();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    void display(){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        while(!st2.empty()){
            cout<<st2.top()<<" ";
            st1.push(st2.top());
            st2.pop();
        }
        cout<<endl;
    }
    int Size(){
        int n = 0;
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
            n++;
        }
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return n;
    }

    bool empty(){
        int n = 0;
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
            n++;
        }
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        if(n == 0) return true;
        else return false;
    }

    int front(){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int n = st2.top();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return n;
    }

    int back(){
        return st1.top();
    }


};

int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.display();
    cout<<q.Size()<<endl;
    cout<<q.empty()<<endl;
    q.pop();
    q.display();
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    return 0;
}