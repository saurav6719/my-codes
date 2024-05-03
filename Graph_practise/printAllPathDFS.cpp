#include<iostream>
#include<vector>
#include<list>
#include<set>
using namespace std;
//question :- you are given two nodes . print all the paths from one node to another 

vector<list<int> > graph;
int v;
void add_edge(int src,int dest, bool directed = false){
    graph[src].push_back(dest);
    if(!directed){
        graph[dest].push_back(src);
    }
}
set<int> visited;
vector<vector<int> >ans;

vector<int> curr;

void allPath(int x, int y){
    curr.push_back(x);
    if(x==y) {
        ans.push_back(curr);
        curr.pop_back();
        return;
    }
    visited.insert(x);
    for(auto ele : graph[x]){
        if(!visited.count(ele) ) allPath(ele,y);
    }
    curr.pop_back();
    visited.erase(x);   
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
    allPath(x,y);
    for(auto ele : ans){
        for(auto ele2 : ele){
            cout<<ele2<<" ";
        }
        cout<<endl;
    }
   //display();
    return 0;
}