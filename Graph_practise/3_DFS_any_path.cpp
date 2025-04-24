#include<iostream>
#include<vector>
#include<list>
#include<set>
using namespace std;

// question -> determine whether any path exists between given two nodes or not

vector<list<int> > graph;
int v;
void add_edge(int src,int dest, bool directed = false){
    graph[src].push_back(dest);
    if(!directed){
        graph[dest].push_back(src);
    }
}


set <int> visited;

void display(){
    for(int i = 0; i<v; i++){
        cout<<i<<"-> ";
        for(auto ele : graph[i]){
            cout<<ele<<", ";
        }
        cout<<endl;
    }
    
}

bool anyPath(int x, int y){
    if(x==y) return true;
    visited.insert(x);
    for(auto ele : graph[x]){
        if(!visited.count(ele)){
            bool res = anyPath(ele, y);
            if(res) return true;
        }
    }
    return false;
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
    cout<<anyPath(x,y);
    // display();
    return 0;
}