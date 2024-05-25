#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to perform DFS and find the longest path to a leaf node
void dfs(const vector<vector<int>>& tree, int node, int parent, int depth, int& maxDepth) {
    // If it's a leaf node (and not the source node), check the depth
    if (tree[node].size() == 1 && node != parent) {
        if (depth > maxDepth) {
            maxDepth = depth;
        }
    }

    for (int neighbor : tree[node]) {
        if (neighbor != parent) {
            dfs(tree, neighbor, node, depth + 1, maxDepth);
        }
    }
}

int main() {
    int n; // Number of nodes
    cout << "Enter number of nodes: ";
    cin >> n;

    // Adjust for 1-indexed graph by initializing tree with n+1 size
    vector<vector<int>> tree(n + 1);
    //cout << "Enter edges (u v) for the tree:" << endl;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int source; // Source vertex
    //cout << "Enter source vertex: ";
    cin >> source;

    // Perform DFS to find the longest path from the source to a leaf node
    int maxDepth = -1;
    dfs(tree, source, -1, 0, maxDepth);

    cout << "The longest path from the source to a leaf node has length: " << maxDepth << endl;

    return 0;
}
