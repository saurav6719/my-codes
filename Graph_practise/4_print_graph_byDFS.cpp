#include<iostream>
#include<vector>
#include<list>
#include<set>
using namespace std;
vector<list<int> > graph;
int v;
void add_edge(int src,int dest, bool directed = false){
    graph[src].push_back(dest);
    if(!directed){
        graph[dest].push_back(src);
    }
}
set <int> visited;

void dfs(int root){
    cout<<root<<" ";
    visited.insert(root);
    for(auto neigh : graph[root]){
        if(!visited.count(neigh)){
            dfs(neigh);
        }
    }
    return; 
}

int main(){
    cin>>v;
    graph.resize(v,list<int> ());
    int e;
    cin>>e;
    while(e--){
        int src,dest;
        cin>>src>>dest;
        add_edge(src,dest);
    }
    int root;
    cin>>root;
    dfs(root);
    return 0;
}