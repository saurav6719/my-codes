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
void topview(node* root){
    unordered_map<int,int> mp;
    queue<pair<node*, int> > q;
    pair<node*, int> r;
    r.first = root;
    r.second = 0;
    q.push(r);
    while(q.size() > 0){
        node * temp = q.front().first;
        int level = q.front().second;
        q.pop();
        if(mp.find(level) == mp.end()) mp[level] = temp -> val;
        if(temp -> left){
            pair<node*, int> p;
            p.first = temp -> left;
            p.second = level - 1 ;
            q.push(p);
        }
        if(temp -> right){
            pair<node*, int> p;
            p.first = temp -> right;
            p.second = level + 1 ;
            q.push(p);
        }
    }
    int minLevel = INT_MAX;
    int maxLevel = INT_MIN;
    for(auto ele : mp){
        int level = ele.first;
        minLevel = min(minLevel,level);
        maxLevel = max(maxLevel, level);
    }
    for(int i = minLevel; i<= maxLevel; i++){
        cout<<mp[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8};
    
    int n = sizeof(arr)/ sizeof(arr[0]);

    node * root = construct(arr, n);

    levelorder(root);
    topview(root);
    return 0;
}