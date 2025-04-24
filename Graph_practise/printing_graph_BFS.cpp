#include<iostream>
#include<vector>
#include<list>
#include<queue>
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

queue <int> qu;
set<int> visited;
void bfs(int root){
    qu.push(root);
    visited.insert(root);
    while(!qu.empty()){
        cout<<qu.front()<<" ";
        for(auto neigh : graph[qu.front()]){
            if(!visited.count(neigh)){
                qu.push(neigh);
                visited.insert(neigh);
            }
        }
        qu.pop();
    }
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
    bfs(root);
    return 0;
}