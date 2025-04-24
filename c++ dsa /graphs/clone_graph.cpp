#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#else
#define debug(x)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;
//link -> https://leetcode.com/problems/clone-graph/submissions/1157297699/
void solve(){
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
vector<Node * > visited;
void dfs(Node *actual, Node * clone){
    for(auto neigh : (actual -> neighbors)){
        if(not visited[neigh -> val]){
            Node * neighb = new Node(neigh -> val);
            visited[neighb -> val] = neighb;
            (clone -> neighbors).push_back(neighb);
            dfs(neigh,visited[neigh -> val]);
        }
        else{
            (clone -> neighbors).push_back(visited[neigh -> val]);
        }
        
    }
}

    Node* cloneGraph(Node* node) {
        if ( node == nullptr) return nullptr;
        visited.resize(110,NULL);
        Node * clone = new Node(node -> val);
        visited[clone -> val] = clone;
        dfs(node,clone);
        return clone;
        

    }
};
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}