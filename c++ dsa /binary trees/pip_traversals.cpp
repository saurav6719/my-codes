#include<iostream>
#include<vector>
#include<stack>
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
void preorder_recursive(node * root){
    if(root == NULL) return;
    cout<<root -> val<<" ";
    preorder_recursive(root -> left);
    preorder_recursive(root -> right);
}


void inorder_recursive(node * root){
    if(root == NULL) return;
    inorder_recursive(root -> left);
    cout<<root -> val<<" ";
    inorder_recursive(root -> right);
}


void postorder_recursive(node * root){
    if(root == NULL) return;
    postorder_recursive(root -> left);
    postorder_recursive(root -> right);
    cout<<root -> val<<" ";
}

void preorder_iterative(node * root){
    vector<int> ans;
    stack<node *> st;
    st.push(root);
    while(st.size()!=0){
        node * temp = st.top();
        ans.push_back(temp -> val);
        st.pop();
        if(temp -> right != NULL) st.push(temp -> right);
        if(temp -> left != NULL) st.push(temp -> left);
    }

    for(int i = 0 ;i< ans.size(); i++){
        cout<<ans[i]<<" ";

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

    preorder_recursive(a);
    cout<<endl;

    inorder_recursive(a);
    cout<<endl;

    postorder_recursive(a);
    cout<<endl;

    preorder_recursive(a);

    return 0;
}