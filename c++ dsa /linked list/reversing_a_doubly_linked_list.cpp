#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node * next;
    Node * prev;
    Node(int val){
        this -> val =  val;
        this -> next = NULL;
        this -> prev = NULL;
    }
    
};

Node * reverse(Node * head){
    Node * current = head;
    Node * tail = head;
    while(tail -> next){
        tail = tail -> next;
    }
    while(current){
        Node * temp = current -> prev;
        current -> prev = current -> next;
        current -> next = temp;
        current = current -> prev;

    }
    return tail;
}
void display(Node * head){
        Node * temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
int main(){
    Node * a = new Node(10);
    Node * b = new Node(20);
    Node * c = new Node(30);
    Node * d = new Node(40);
    Node * e = new Node(50);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    
    e->prev = d;
    d->prev = c;
    c->prev = b;
    b->prev = a;
    display(a);

    display(reverse(a));
    

}