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
class doublyLinkedList{
public:
    node *head;
    node *tail;
    int size;
    doublyLinkedList(){
        head = tail = NULL;
        size = 0;
    }
    void insertAtend(int val){
        node * temp = new node(val);
        if(size == 0) head = tail = temp;
        else{
            tail->next = temp;
            temp -> prev = tail;
            tail = temp;
        }
        size++;
    }
    void insertAtBegin(int val){
        node * temp = new node(val);
        if(size == 0) head = tail = temp;
        else{
            temp->next = head;
            head -> prev = temp;
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
        t -> next = temp -> next;
        temp -> next = t;
        t -> prev = temp;
        t -> next -> prev = t; 
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
            if(index < size / 2){
                node *temp = head;
                for (int i = 1; i <= index; i++){
                    temp = temp->next;
                }
                return temp->value;
            }
            else{
                node * temp = tail;
                for(int i =1;i< size - index;i++){
                temp = temp->prev;
                }
                return temp->value;
            }
        }

    }
    void deleteAtHead(){
        if(size == 0){
            cout<<"your list is empty";
            return;
        }
        if(head) head = head->next;
        else tail = NULL;
        size--;
    }
    void deleteAtTail(){
        
        if(size == 0){
            cout<<"your list is empty";
            return;
        }
        if(size == 1){
            deleteAtHead();
            return;
        }

        node * temp = tail -> prev;
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
            temp -> next -> prev = temp;
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
    doublyLinkedList ll;
    ll.insertAtBegin(10);
    ll.insertAtBegin(20);
    ll.insertAtBegin(30);
    ll.insertAtend(40);
    ll.insertAtend(50);
    ll.insertAtend(60);
    ll.insertAtend(70);
    ll.insertAtend(80);
    
    ll.display();
    
    cout<< ll.getIndex(0)<<endl;
    cout<< ll.getIndex(1)<<endl;
    cout<< ll.getIndex(2)<<endl;
    cout<< ll.getIndex(3)<<endl;
    cout<< ll.getIndex(4)<<endl;
    cout<< ll.getIndex(05)<<endl;
    cout<< ll.getIndex(06)<<endl;




    return 0;
}