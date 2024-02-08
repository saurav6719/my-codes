#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

vector<list<int> >graph;
queue<int> qu;
int v ; // number of vertices 

void add_edge(int src, int dest, bool  undirected = true){
    graph[src].push_back(dest);
    if(undirected){
        graph[dest].push_back(src);
    }
}

bool bfs(int src){
    unordered_set<int>  vis;
    vector<int> parent(v,-1);
    qu.push(src);
    vis.insert(src);
    while(!qu.empty()){
        int curr = qu.front();
        qu.pop();
        for(auto neigh : graph[curr]){
            if(vis.count(neigh) and parent[curr] != neigh){
                //cycle detected
                return true;
            }
            if(vis.count(neigh) == 0){
                vis.insert(neigh);
                parent[neigh] = curr;
                qu.push(neigh);
            }
        }
    }
    return false;
}

bool hasCycle(){
    unordered_set<int>  vis;
    for(int i = 0; i<v; i++){
        if(!vis.count(i)){
            bool b  = bfs(i);
            if(b==true) return true;
        } 
    }
    return false;
}

int main(){
    cin>>v;
    graph.resize(v,list<int> ());
    int e;
    cin>>e;// no of edges
    while(e--){
        int src, dest;
        cin>>src>>dest;
        add_edge(src,dest);
    }
    bool b = hasCycle();
    if(b==1) cout<<"CYCLE DETECTED";
    else cout<<"NO CYCLE";
    return 0;
    return 0;
}