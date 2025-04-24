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
node* deleteNode(node * head, node * target ){
    if(head == target ){
        head = head->next;
        return head;
    }
    node * temp = head;
    while(temp->next != target){
        temp = temp->next;
    }
    temp->next = (temp->next)->next;
    return head;
}
void display(node * head){
    node * temp = head;
    
    while(temp != NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    node * a = new node(10);
    node * b = new node(20);
    node * c = new node(30);
    node * d = new node(40);
    node * e = new node(50);
    
    node * head = a;
    a-> next = b; 
    b-> next = c;
    c-> next = d;
    d-> next = e;
    display(head);
    head = deleteNode(a,a);
    display(head);
    return 0;
}