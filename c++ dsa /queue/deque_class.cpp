#include<iostream>
using namespace std;
class node{
public:
    int value;
    node * next;
    node * prev;
    node( int value){
        this -> value = value;
        this -> next = NULL;
        this -> prev = NULL;
    }
};
class deque{
public:
    node *head;
    node *tail;
    int size;
    deque(){
        head = tail = NULL;
        size = 0;
    }
    void push_back(int val){
        node * temp = new node(val);
        if(size == 0) head = tail = temp;
        else{
            tail->next = temp;
            temp -> prev = tail;
            tail = temp;
        }
        size++;
    }
    void push_front(int val){
        node * temp = new node(val);
        if(size == 0) head = tail = temp;
        else{
            temp->next = head;
            head -> prev = temp;
            head = temp;
        }
        size++;
    }
    
    void pop_front(){
        if(size == 0){
            cout<<"your list is empty";
            return;
        }
        if(head) head = head->next;
        else tail = NULL;
        size--;
    }
    void pop_back(){
        
        if(size == 0){
            cout<<"your list is empty";
            return;
        }
        if(size == 1){
            pop_front();
            return;
        }

        node * temp = tail -> prev;
        temp->next = NULL;
        tail = temp;
        size--;
    }
    
    void display(){
        node * temp = head;
        while(temp != NULL){
            cout<<temp->value<<" ";
            temp = temp->next;
        }
        cout<<endl;
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
        if (size == 0) return true;
        else return false;
    }

};
int main(){
    deque q;
    q.push_front(10);
    q.push_front(20);
    q.push_front(30);
    q.push_front(40);
    q.push_front(50);
    q.push_back(60);
    q.display();
    cout<<q.Size()<<endl;
    cout<<q.empty()<<endl;
    q.pop_back();
    q.display();
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    return 0;
}