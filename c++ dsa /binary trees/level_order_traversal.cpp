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


int levels(node * root){
    if(root == NULL) return 0;
    return 1 + max(levels(root -> left), levels(root -> right));  
}

void nthLevel(node * root,int current , int n){
    if(root == NULL) return;
    if(current == n) cout<<root -> val <<" ";
    
    
    nthLevel(root ->left,current+1,n);
    nthLevel(root ->right,current+1,n);

}
void levelorder(node * root){
    int n = levels(root);
    for(int i = 1; i<=n ; i++){
        nthLevel(root, 1, i);
        cout<<endl;
    }
}

int main(){
    node * a = new node(1);
    node * b = new node(2);
    node * c = new node(3);
    node * d = new node(4);
    node * e = new node(5);
    node * f = new node(6);
    node * g = new node(7);

    a -> left = b;
    a -> right = c;

    b -> left = d;
    b -> right = e;

    c -> left = f;
    c -> right = g;

    levelorder(a);

    return 0;
}
