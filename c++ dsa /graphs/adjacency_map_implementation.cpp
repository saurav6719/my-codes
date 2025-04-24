#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

vector<unordered_map<int, int> > graph;
int v ; // number of vertices 

void add_edge(int src, int dest,int weight , bool  undirected = true){
    graph[src][dest] = weight;
    if(undirected){
        graph[dest][src] = weight;
    }
}

void display(){
    for(int i = 0; i< graph.size(); i++){
        cout<<i<<" -> ";
        for(auto ele : graph[i]){
            cout<<"{ "<<ele.first<<", "<< ele.second<<" }"<<",";
        }
        cout<<endl;
    }
}


int main(){
    cin>>v;
    graph.resize(v,unordered_map <int,int>  ());
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