#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct Edge {
    int source, destination, weight;
};

void bellmanFord(int vertices, int edges, vector<Edge>& graph, int startVertex) {
    vector<int> distance(vertices, numeric_limits<int>::max());
    distance[startVertex] = 0;

    for (int i = 1; i <= vertices - 1; ++i) {
        for (int j = 0; j < edges; ++j) {
            int u = graph[j].source;
            int v = graph[j].destination;
            int weight = graph[j].weight;
            if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    for (int j = 0; j < edges; ++j) {
        int u = graph[j].source;
        int v = graph[j].destination;
        int weight = graph[j].weight;
        if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
            cout << "Graph contains a negative-weight cycle" << endl;
            return;
        }
    }

    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < vertices; ++i) {
        cout << i << "\t\t" << distance[i] << endl;
    }
}

int main() {
    int vertices, edges, startVertex;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    vector<Edge> graph(edges);

    cout << "Enter the edges (source destination weight):" << endl;
    for (int i = 0; i < edges; ++i) {
        cin >> graph[i].source >> graph[i].destination >> graph[i].weight;
    }

    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    bellmanFord(vertices, edges, graph, startVertex);

    return 0;
}
