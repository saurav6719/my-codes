
#include<iostream>
#include<list>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int> > graph;
queue<int> q;
int v; // number of vertices
unordered_set<int> visited;
void add_edge(int src, int dest, bool undirected = true) {
    graph[src].push_back(dest);
    if (undirected) {
        graph[dest].push_back(src);
    }
}
void topobfs(){
    vector<int> indegree(v,0);
    queue<int> qu;
    for(int i = 0; i<v;i++){
        for(auto neigh : graph[i]){
            indegree[neigh]++;
        }
    }
    for(int i =0; i<v; i++){
        if(indegree[i] == 0) {
            qu.push(i);
            visited.insert(i);
        }
    }
    while(not qu.empty()){
        auto cell = qu.front();
        cout<<cell<<" ";
        qu.pop();
        for(auto neighbour: graph[cell]){
            if(not visited.count(neighbour)){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    qu.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }   
    }
}
int main() {
    cin >> v;
    graph.resize(v, vector<int>());
int e;
    cin >> e; // no of edges
    visited.clear();
    while (e--) {
        int src, dest;
        cin >> src >> dest;
        add_edge(src, dest, false);
    }
    topobfs();
    return 0;
}