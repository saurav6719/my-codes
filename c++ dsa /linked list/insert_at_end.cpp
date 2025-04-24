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
void display(node * head){
    node * temp = head;
    
    while(temp != NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void insertAtEnd(node * t , node * head){
    node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;;
    }
    temp->next = t;
}

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
    display(a);
   
    node * t = new node(60);
    insertAtEnd(t,a);
    display(a);
    
    return 0;
}