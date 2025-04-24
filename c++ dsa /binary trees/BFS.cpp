#include<iostream>
#include<queue>
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

void bfs( node * &root){
    queue<node*> q;
    q.push(root);
    while(q.size() != 0){
        node * temp = q.front();
        q.pop();
        cout<<temp -> val<<" ";
        if(temp -> left != NULL) q.push(temp -> left);
        if(temp -> right != NULL) q.push(temp -> right);
    }
    cout<<endl;
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

    bfs(a);
    return 0;
}
