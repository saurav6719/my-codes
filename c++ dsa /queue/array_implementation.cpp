#include<iostream>
#include<vector>
using namespace std;
class Queue{
    public:
    int f;
    int b;
    vector<int> arr;
    Queue(int size){
        f=0;
        b=0;
        vector<int> v(size);
        arr = v;
    }
    void push(int val){
        if(b== arr.size()) {
            cout<<"Queue is full !"<<endl;
            return;
        }
        arr[b] = val;
        b++;
    }
    void pop(){
        if(f-b == 0){
            cout<<"queue is empty"<<endl;
            return;
        }
        f++;
    }
    int front(){
        if(f-b == 0){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return arr[f];

    }
    int back(){
        if(b-f == 0){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return arr[b-1];
    }
    int size(){
        return b-f;
    }
    bool empty(){
        if(f-b == 0) return true;
        else return false;
    }
    void display(){
        for(int i = f; i<b; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};
int main(){
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    // q.push(60);
    q.display();
    cout<<"current size of queue is "<<q.size()<<endl;
    cout<<"is queue empty? "<<q.empty()<<endl;
    q.pop();
    q.display();
    cout<<"front element is "<<q.front()<<endl;
    cout<<"back element is "<<q.back()<<endl;
   

}