#include<iostream>
#include<list>
#include<vector>

using namespace std;

vector<list<pair<int, int> > > graph;
int v ; // number of vertices 

void add_edge(int src, int dest,int weight , bool  undirected = true){
    graph[src].push_back({dest, weight});
    if(undirected){
        graph[dest].push_back({src, weight});
    }
}

void display(){
    for(int i = 0; i< graph.size(); i++){
        cout<<i<<" -> ";
        for(auto ele : graph[i]){
            cout<<ele.first<<" "<< ele.second<<", ";
        }
        cout<<endl;
    }
}


int main(){
    cin>>v;
    graph.resize(v,list<pair<int,int> > ());
    int e;
    cin>>e;// no of edges
    while(e--){
        int src, dest, weight;
        cin>>src>>dest>>weight;
        add_edge(src,dest,weight);
    }
    display();
    return 0;
}