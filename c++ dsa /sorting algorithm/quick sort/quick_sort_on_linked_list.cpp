#include <iostream>
using namespace std;
class node {
    public:
    int val;
    node* next;
    node(int val){
        this ->val = val;
        this -> next = NULL;
    }
};
node * gettail(node * head){
    while(head != NULL and head -> next != NULL){
        head = head -> next;
    }
    return head;
}
node * partition(node * head, node * end, node ** newhead, node **newend){
    node * pivot = end;
    node * prev = nullptr;
    node * current = head;
    node * tail = pivot;
    while(current != pivot){
        if(current -> val < pivot ->val ){
            if(*newhead == nullptr){
                *newhead = current;
            }
            prev = current;
            current = current -> next;
        }
        else{
            if(prev){
                prev -> next = current -> next;
            }
            else {
                *newhead = current->next; // Update newhead if prev is nullptr
            }

            node * temp = current -> next;
            current -> next = nullptr;
            tail -> next = current;
            tail = current;
            current = temp;

        }
    }

    if(*newhead == NULL){
        *newhead = pivot;
        *newend = pivot;
    }
    else {
        *newend = tail; // Update newend if newhead is not nullptr
    }
    *newend = tail;
    return pivot;
}

node * quicksort(node * head, node * tail){
    if(!head or head == tail){
        return head;
    }
    node * newhead = nullptr;
    node * newtail = nullptr;

    node * pivot = partition(head , tail , &newhead , &newtail);
    if(newhead != pivot){
        node * temp = newhead;
        while(temp -> next != pivot){
            temp = temp -> next;
        }
        temp -> next = nullptr;

        newhead = quicksort(newhead , temp);
        temp = gettail(newhead);
        temp -> next = pivot;
    }

    pivot -> next = quicksort(pivot -> next , newtail);
    return newhead;
}


void print(node *head){
    while(head != NULL){
        cout<<head->val<<" ";
        head = head -> next;
    }
    cout<<endl;
}

int main() {
    node *a = new node(4);
    node *b = new node(6);
    node *c = new node(8);
    node *d = new node(2);
    node *e = new node(5);
    node *f = new node(3);
    node *g = new node(7);
    node *h = new node(1);

    a -> next = b;
    b ->next = c;
    c -> next = d;
    d -> next = e;
    e -> next = f;
    f -> next = g;
    g -> next = h;

    cout<<"original linked list "<<endl;
    print(a);


    node * tail = gettail(a);
    a = quicksort(a, tail);
    cout<<"sorted linked list"<<endl;
    print(a);



    return 0;
}