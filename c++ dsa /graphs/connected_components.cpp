#include<iostream>
#include<list>
#include<vector>
#include<unordered_set>

using namespace std;
int coc = 0;
vector<list<int> > graph;
unordered_set<int> visited;
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

void dfs(int root){
    visited.insert(root);
    for(auto neighbour : graph[root] ){
        if(! visited.count(neighbour)){
            dfs(neighbour);
        }
    }
    return ;
}

void cc(){
    for(int i = 0; i<graph.size(); i++){
        if(visited.count(i) == 0){
            dfs(i);
            coc++;
        }
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
    cc();
    cout<<coc<<endl;
    


    return 0;
}