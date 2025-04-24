#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
vector<vector<int> > graph;
int v ; // number of vertices 
void add_edge(int src, int dest, bool  undirected = true){
    graph[src][dest] = 1;
    if(undirected){
        graph[dest][src] = 1;
    }
}
bool dfs(int src,  int parent , unordered_set<int> & vis){
    vis.insert(src);
    for (int neigh = 0; neigh < v; ++neigh) {
        if (graph[src][neigh] == 1) {
            if (vis.count(neigh) && neigh != parent) {
                // Cycle detected
                return true;
            }
            if (!vis.count(neigh)) {
                bool result = dfs(neigh, src, vis);
                if (result == true) return true;
            }
        }
    }
    return false;
}

bool hasCycle(){
    unordered_set<int>  vis;
    for(int i = 0; i<v; i++){
        if(!vis.count(i)){
            bool b  = dfs(i,-1,vis);
            if(b==true) return true;
        } 
    }
    return false;
}
int main(){
    cin>>v;
    graph.resize(v,vector<int>(v,0));
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
}