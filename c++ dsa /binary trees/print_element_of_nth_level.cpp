#include<iostream>
using namespace std;
class node{
public:
    int val;
    node * left;
    node * right;
    node(int val){
        this -> val = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};
void nthLevel(node * root,int current , int n){
    if(root == NULL) return;
    if(current == n) cout<<root -> val <<" ";
    nthLevel(root ->left,current+1,n);
    nthLevel(root ->right,current+1,n);
}



int main(){
    node * a = new node(1);
    node * b = new node(7);
    node * c = new node(9);
    node * d = new node(2);
    node * e = new node(6);
    node * f = new node(8);
    node * g = new node(9);

    a -> left = b;
    a -> right = c;

    b -> left = d;
    b -> right = e;

    c -> left = f;
    c -> right = g;

    nthLevel(a, 1 ,2);
    return 0;
}
