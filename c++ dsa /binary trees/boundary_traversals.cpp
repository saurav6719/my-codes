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

node * construct(int arr[], int n){
    queue<node *> q;
    node * root = new node (arr[0]);
    q.push(root);
    int i = 1;
    int j = 2;
    while(q.size() != 0 and i<n){
        node * temp = q.front();
        q.pop();

        node * l; 
        node * r;
        if(arr[i] != INT_MIN){
            l = new node(arr[i]);
        }
        else l = NULL;

        if(j<n and arr[j] != INT_MIN){
            r = new node(arr[j]);
            
        }
        else r = NULL;

        temp -> left = l;
        temp -> right  = r;
         
        if(l != NULL) q.push(l);
        if(r != NULL) q.push(r);

        i += 2;
        j += 2;
    }
    return root;
}
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

void left_boundary(node * root){
    if(root == NULL) return;
    if(root -> left == NULL and root -> right == NULL) return;
    cout<<root -> val<<" ";
    if(root -> left == NULL) left_boundary(root -> right);
    else left_boundary(root -> left);
}

void leaf_node(node * root){
    if(root == NULL) return;
    if(root -> left == NULL and root -> right == NULL) cout<<root -> val<<" ";
    leaf_node(root -> left);
    leaf_node(root -> right);
}

void right_boundary(node * root){
    if(root == NULL) return;
    if(root -> left == NULL and root -> right == NULL) return;
    
    if(root -> right == NULL) right_boundary(root -> left);
    else right_boundary(root -> right);
    cout<<root -> val<<" ";
}

int main(){
    int arr[] = {1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,INT_MIN,28,INT_MIN,INT_MIN};
    
    int n = sizeof(arr)/ sizeof(arr[0]);

    node * root = construct(arr, n);



    //levelorder(root);
    left_boundary(root);
    
    leaf_node(root);
    
    right_boundary(root -> right);

    return 0;
}