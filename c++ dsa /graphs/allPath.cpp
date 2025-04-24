#include<iostream>
#include<list>
#include<unordered_set>
#include<vector>

using namespace std;

vector<list<int> > graph;
vector<vector<int> > result;
int v ; // number of vertices 
unordered_set<int> visited;

void add_edge(int src, int dest, bool undirected = true){
    graph[src].push_back(dest);
    if(undirected){
        graph[dest].push_back(src);
    }
}

void dfs(int curr, int end , vector<int> &path){
    if (curr == end) {
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr);
    path.push_back(curr);
    for(auto neighbour : graph[curr] ){
        if(! visited.count(neighbour)){
            dfs(neighbour,end,path);
        }
    }
    path.pop_back();
    visited.erase(curr);
    return ;
}

void allPath(int src, int dest){
    vector<int> v;
    return dfs(src,dest,v);
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
    allPath(x,y);
    for(int i = 0; i<result.size(); i++){
        for(int j= 0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}