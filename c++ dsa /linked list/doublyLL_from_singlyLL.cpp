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

class Node{
public:
    int value;
    Node * next;
    Node * prev;
    Node( int value){
        this -> value = value;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

int main(){
    node * a = new node(10);
    node * b = new node(20);
    node * c = new node(30);
    node * d = new node(40);
    node * e = new node(50);

    a-> next = b; 
    b-> next = c;
    c-> next = d;
    d-> next = e;

    node * current = a;
    Node * previous = NULL;
    Node * Next = NULL;
    Node * head = NULL;
    while(current){
        Node * temp = new Node(current -> value);
        temp -> prev = previous;
        if(temp -> prev == NULL) head = temp;
        temp -> next = Next;
        if(temp -> prev != NULL) temp -> prev -> next = temp;
        current = current -> next;
        previous = temp;
    }
    while(head){
        cout<<head -> value<<" ";
        head = head -> next;
    }
    return 0;
}