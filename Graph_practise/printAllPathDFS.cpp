#include<iostream>
#include<vector>
#include<list>
#include<set>
using namespace std;
vector<list<int> > graph;
int v;
void add_edge(int src,int dest, bool directed = false){
    graph[src].push_back(dest);
    if(!directed){
        graph[dest].push_back(src);
    }
}
set <int> visited;
vector<int> path;
vector<vector<int> > res;
void dfs(int src, int dest){
    if(src == dest){
        path.push_back(src);
        res.push_back(path);
        path.pop_back();
        return ;
    }
    path.push_back(src);
    visited.insert(src);
    for(auto neighbour : graph[src]){
        if(! visited.count(neighbour)){
            dfs(neighbour, dest);
        }
    }
    path.pop_back();
    visited.erase(src);
}
void display(){
    for(int i = 0; i<v; i++){
        cout<<i<<"-> ";
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
    cin>>e;
    while(e--){
        int src,dest;
        cin>>src>>dest;
        add_edge(src,dest);
    }
    int x;
    int y;
    cin>>x>>y;
    dfs(x,y);
    for(int i = 0; i<res.size(); i++){  
        for(int j = 0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
   //display();
    return 0;
}