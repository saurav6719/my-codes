#include<iostream>
using namespace std;
class node{
public:
    int value;
    node * next;
    node( int value){
        this -> value = value;
        this -> next = NULL;
    }
};
class Queue{
public:
    node *head;
    node *tail;
    int size;
    Queue(){
        head = tail = NULL;
        size = 0;
    }
    void push(int val){
        node * temp = new node(val);
        if(size == 0) head = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void pop(){
        if(size == 0){
            cout<<"your list is empty";
            return;
        }
        node * temp = head;
        head = head->next;
        size--;
        delete(temp);
    }
    int front(){
        return head -> value;
    }
    int back(){
        return tail -> value;
    }
    int Size(){
        return size;
    }
    bool empty(){
        if(size == 0) return true;
        else return false;
    }
    void display(){
        node * temp = head;
        while(temp != NULL){
            cout<<temp->value<<" ";
            temp = temp->next;
        }
        cout<<endl;
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