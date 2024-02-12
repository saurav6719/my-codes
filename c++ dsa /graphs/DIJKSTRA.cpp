#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#define ll long long int
#define pp pair<int,int>
using namespace std;
vector<list<pp> >gr;
void add_edge(int u, int v, int wt,bool bidir = true){
    gr[u].push_back({v,wt});
    if(bidir){
        gr[v].push_back({u,wt});
    }
}
unordered_map<int,int>  dijkstra(int src, int n){
    priority_queue<pp, vector<pp>, greater<pp> > pq;
    unordered_set<int> vis;
    vector<int> via(n+1);
    unordered_map<int,int> mp; // distance ,  node
    for(int i = 1; i<=n; i++){
        mp[i] = INT_MAX; // start me sab infinity
    }
    pq.push({0,src});
    mp[src] = 0;
    while(!pq.empty()){ // tree me max n-1 edges 
        pp curr = pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        pq.pop();
        for(auto neighbour : gr[curr.second]){
            if(!vis.count(neighbour.first) and mp[neighbour.first] > mp[curr.second]+neighbour.second){
                pq.push({mp[curr.second]+neighbour.second, neighbour.first});
                via[neighbour.first] = curr.second;
                mp[neighbour.first] = mp[curr.second]+neighbour.second;
            }
            
        }
    }
    return mp;
}
int main(){
    int n,m;
    cin>>n>>m;
    gr.resize(n+1,list<pair<int,int> > ()); // n+1 for 1 based indexing
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;   
        add_edge(u,v,wt);
    }
    int src;
    cin>>src;
    unordered_map<int,int> shortest_path = dijkstra(src,n);
    int dest;
    cin>>dest;
    cout<<shortest_path[dest]<<endl;
    return 0;
}