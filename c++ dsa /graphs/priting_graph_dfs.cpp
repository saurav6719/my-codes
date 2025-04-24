#include<iostream>
#include<list>
#include<unordered_set>
#include<vector>

using namespace std;

vector<list<int> > graph;
int v ; // number of vertices 
unordered_set<int> visited;

void add_edge(int src, int dest, bool undirected = true){
    graph[src].push_back(dest);
    if(undirected){
        graph[dest].push_back(src);
    }
}

void dfs(int root){
    cout<<root<<" ";
    visited.insert(root);
    for(auto neighbour : graph[root] ){
        if(! visited.count(neighbour)){
            dfs(neighbour);
        }
    }
    return ;
}

int main(){
    cin>>v;
    graph.resize(v,list<int> ());
    int e;
    cin>>e;// no of edges
    visited.clear();
    while(e--){
        int src, dest;
        cin>>src>>dest;
        add_edge(src,dest);
    }
    int root = 0;
    dfs(root);
    return 0;
}