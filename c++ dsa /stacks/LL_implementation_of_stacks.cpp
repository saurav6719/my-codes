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
class stack{
    public:
    node * head;
    int size;
    stack(){
        head = NULL;
        size = 0;
    }
    void push(int val){
        node * temp = new node(val);
        temp -> next = head;
        head = temp ;
        size++;
    }

    void pop(){
    if (head != NULL) {
        head = head->next;
        size--;
    } else {
        cout << "Stack is empty. Cannot pop." << endl;
    }
    }

    
    int top(){
    if (head != NULL) {
        return head->value;
    } else {
        cout << "Stack is empty. Cannot get top element." << endl;
        return -1; // Return a default value or handle the error as needed.
    }
    }
    // void display(){
    //     node * temp = head;
    //     while(temp){
    //         cout<<temp -> value<<" ";
    //         temp = temp -> next;
    //     }
    //     cout<<endl;
    // }
    void print(node * head){
        if(head == NULL) return;
        print(head -> next);
        cout<<head -> value<<" ";
    }
    void display(){
        node * temp = head ;
        print(temp);
        cout<<endl;
    }
    

};
int main(){
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    st.push(80);

    cout<<st.size<<endl;
    st.pop();
    cout<<st.size<<endl;
    cout<<st.top()<<endl;
    st.display();
    return 0;
}
