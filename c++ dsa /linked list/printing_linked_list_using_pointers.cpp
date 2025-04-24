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
int main(){
    node * a = new node(10);
    node * b = new node(20);
    node * c = new node(30);
    node * d = new node(40);
    

    a-> next = b; // b ek pointer hai jo new node(20) ke address ko store kr rha ,, ab a k next me us address ko daal do mtlb new node(20) k address ko daal do
    b-> next = c;
    c-> next = d;
    cout<<a->next->next->next->value<<endl;

    // node *temp = a; // temp naam ka ek dabba bna jisme a node copy ho gya 
    // while(temp != NULL){
    //     cout<<temp->value<<" ";
    //     temp = temp->next; // temp node k next pe b ka address tha to ab temp me b ki value copy ho jayengi //similar to temp = b;
    // }

    return 0;
}