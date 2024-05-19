#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define INF INT_MAX

// A function to print the solution matrix
void printSolution(const vector<vector<int>>& dist) {
    cout << "The following matrix shows the shortest distances"
         << " between every pair of vertices\n";
    for (size_t i = 0; i < dist.size(); i++) {
        for (size_t j = 0; j < dist.size(); j++) {
            if (dist[i][j] == INF)
                cout << "INF" << "     ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}

// Function to implement Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>>& graph) {
    size_t V = graph.size();
    vector<vector<int>> dist = graph;

    for (size_t k = 0; k < V; k++) {
        for (size_t i = 0; i < V; i++) {
            for (size_t j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist);
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> graph(V, vector<int>(V, INF));

    for (int i = 0; i < V; ++i) {
        graph[i][i] = 0;
    }

    cout << "Enter the edges (source destination weight) format:\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    floydWarshall(graph);

    return 0;
}
