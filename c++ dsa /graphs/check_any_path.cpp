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

bool dfs(int curr, int end){
    if (curr == end) return true;
    visited.insert(curr);
    for(auto neighbour : graph[curr] ){
        if(! visited.count(neighbour)){
            bool result = dfs(neighbour, end);
            if(result == true) return true;
        }
    }
    return false;
}

bool anyPath(int src, int dest){
    return dfs(src,dest);
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
    int x,y;
    cin>>x>>y;
    cout<<anyPath(x,y)<<endl;
    
    return 0;
}