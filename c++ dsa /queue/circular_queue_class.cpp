#include<iostream>
#include<vector>
using namespace std;
class Queue{
    public:
    int f;
    int b;
    int s;
    int c; // capacity
    vector<int> arr;
    Queue(int size){
        f=0;
        b=0;
        s=0;
        c=size;
        vector<int> v(size);
        arr = v;
    }
    void push(int val){
        if( s == c) {
            cout<<"Queue is full !"<<endl;
            return;
        }
        arr[b] = val;
        b++;
        if(b==c) b=0;  // circle
        s++;
    }
    void pop(){
        if(s == 0){
            cout<<"queue is empty"<<endl;
            return;
        }
        f++;
        if(f == c) f = 0;  // agar f ek circle ghum gya to usko v 0 par le aao 
        s--;
    }
    int front(){
        if(s == 0){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return arr[f];

    }
    int back(){
        if(s == 0){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        if(b == 0) return arr[c-1]; // b agar 0 par hai aur size 0 nhi hai matlab b ek circle ghum gya hoga to last element last me hi hoga 
        return arr[b-1];
    }
    int size(){
        return s;
    }
    bool empty(){
        if(s == 0) return true;
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
    //q.push(60);
    q.display();
    cout<<"current size of element is "<<q.size()<<endl;
    cout<<"is queue empty? "<<q.empty()<<endl;
    q.pop();
    q.display();
    cout<<"front element of queue is "<<q.front()<<endl;
    cout<<"back element of queue is "<<q.back()<<endl;
}