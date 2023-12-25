#include<iostream>
#include<list>
#include<unordered_set>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int> > graph;
queue<int> q;
int v; // number of vertices
unordered_set<int> visited;

void add_edge(int src, int dest, bool undirected = true) {
    graph[src].push_back(dest);
    if (undirected) {
        graph[dest].push_back(src);
    }
}

void bfs(int root) {
    cout << root << " ";
    q.push(root);
    visited.insert(root);
    while (!q.empty()) {
        for (int i = 0; i<graph[q.front()].size(); i++) {
            int neighbour = graph[q.front()][i];
            if (!visited.count(neighbour)) {
                q.push(neighbour);
                cout << neighbour << " ";
                visited.insert(neighbour);
            }
        }
        q.pop();
    }
    return;
}

int main() {
    cin >> v; 
    graph.resize(v, vector<int>());
    int e;
    cin >> e; // no of edges
    visited.clear();
    while (e--) {
        int src, dest;
        cin >> src >> dest;
        add_edge(src, dest);
    }
    int root = 0;
    bfs(root);
    return 0;
}
