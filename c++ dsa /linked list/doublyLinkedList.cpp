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
int main(){
    Node * a = new Node(10);
    Node * b = new Node(10);
    Node * c = new Node(10);
    Node * d = new Node(10);
    Node * e = new Node(10);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    
    e->prev = d;
    d->prev = c;
    c->prev = b;
    b->prev = a;
    

}