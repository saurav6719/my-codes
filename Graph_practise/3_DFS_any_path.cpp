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
bool dfs(int src, int dest){
    if(src==dest) return true;
    visited.insert(src);
    for(auto neigh : graph[src]){
        if(!visited.count(neigh) ) {
            bool ans = dfs(neigh, dest);
            if(ans = true) return true;
        }
    }
    return false;
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
    cout<<dfs(x,y);
    display();
    return 0;
}