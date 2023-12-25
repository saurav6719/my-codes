#include<iostream>
#include<unordered_map>
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

void display(){
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j< graph[0].size(); j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
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
    display();
    return 0;
}