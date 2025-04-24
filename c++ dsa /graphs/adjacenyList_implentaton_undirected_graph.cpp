#include<iostream>
#include<list>
#include<vector>

using namespace std;

vector<list<int> > graph;
int v ; // number of vertices 

void add_edge(int src, int dest, bool undirected = true){
    graph[src].push_back(dest);
    if(undirected){
        graph[dest].push_back(src);
    }
}

void display(){
    for(int i = 0; i< graph.size(); i++){
        cout<<i<<" -> ";
        for(auto ele : graph[i]){
            cout<<ele<<", ";
        }
        cout<<endl;
    }
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
    display();
    return 0;
}