#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
vector<int> a;
vector<long long> subtreeSum;
vector<int> originalA;

// DFS to calculate subtree sums
void dfs(int v) {
    subtreeSum[v] = a[v];
    for (int u : tree[v]) {
        dfs(u);
        subtreeSum[v] += subtreeSum[u];
    }
}

// Function to check if any subtree sum is negative
bool hasNegativeSubtreeSum(int v) {
    if (subtreeSum[v] < 0) {
        return true;
    }
    for (int u : tree[v]) {
        if (hasNegativeSubtreeSum(u)) {
            return true;
        }
    }
    return false;
}

// Function to decrease the value for all vertices in the subtree
void decreaseSubtree(int v, int decreaseValue) {
    for (int u : tree[v]) {
        a[u] -= decreaseValue;
        decreaseSubtree(u, decreaseValue);
    }
}

// Function to simulate the operation
bool performOperation(int increaseValue) {
    // Copy the original values
    a = originalA;
    
    // Perform the increase and decrease operations
    a[1] += increaseValue;
    decreaseSubtree(1, increaseValue);

    // Recalculate subtree sums with DFS
    dfs(1);

    // Check for negative subtree sums
    return hasNegativeSubtreeSum(1);
}

int main() {
    int n;
    cin >> n;

    tree.resize(n + 1);
    a.resize(n + 1);
    originalA.resize(n + 1);
    subtreeSum.resize(n + 1, 0);

    // Input values at each vertex
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        originalA[i] = a[i];
    }

    // Input the parent of each vertex from 2 to n
    for (int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        tree[parent].push_back(i);
    }

    // Calculate initial subtree sums with DFS
    int lo = a[1];
    // debug(lo);
    int hi = 1e15;
    int res = a[1];
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(!performOperation(mid - originalA[1])){
            res = mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }

    cout<<res<<endl;

    return 0;
}
