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
class LinkedList{
public:
    node *head;
    node *tail;
    int size;
    LinkedList(){
        head = tail = NULL;
        size = 0;
    }
    void insertAtend(int val){
        node * temp = new node(val);
        if(size == 0) head = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void insertAtBegin(int val){
        node * temp = new node(val);
        if(size == 0) head = tail = temp;
        else{
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void insertAtIndex(int index, int value){
        if(index == 0){
            insertAtBegin(value);
            return;
        }
        if(index == size){
            insertAtend(value);
            return;
        }
        if(index < 0 or index >size){
            cout<<"invalid index";
            return;
        }

        node * t = new node(value);
        node * temp = head;
        for(int i =1; i<=index-1 ;i++){
            temp = temp->next;
        }
        t->next = temp->next;
        temp->next = t;
        size++;
        return;
    }
    int getIndex(int index){
        if(index < 0 or index > size ){
            cout<<"invalid index";
            return -1;
        }
        else if(index == 0) return head->value;
        else if(index == size - 1) return tail->value;
        else{
            node * temp = head;
            for(int i =1;i<=index;i++){
                temp = temp->next;
            }
            return temp->value;
        }

    }
    void deleteAtHead(){
        if(size == 0){
            cout<<"your list is empty";
            return;
        }
        head = head->next;
        size--;
    }
    void deleteAtTail(){
        node * temp = head;
        if(size == 0){
            cout<<"your list is empty";
            return;
        }
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        tail = temp;
        size--;
    }
    void deleteAtIndex(int index){
        if(index < 0 or index >= size - 1){
            cout<<"invalid index";
            return;
        }
        if(index == 0 ) return deleteAtHead();
        if(index == size - 1) return deleteAtTail();
        else{
            node * temp = head;
            for(int i =1; i<=index-1;i++){
                temp = temp->next;
            }
            temp->next = (temp->next)->next;
            size--;
        }
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
    LinkedList ll;
    ll.insertAtend(10);
    ll.insertAtend(20);
    ll.insertAtend(30);
    ll.insertAtend(40);
    ll.insertAtend(50);
    
    cout<<"queue is ";
    ll.display();
    ll.deleteAtTail();
    cout<<"queue is ";
    ll.display();
    

    return 0;
}