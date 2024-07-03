#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
bool isSafe(vector<vector<int>> &grid, int i, int j, int n) {
    return i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == -1;
}
 
void display(vector<vector<int>> &grid, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
   
}
 
vector<pair<int, int>> getNextMoves(int i, int j) {
    return {{i+2, j+1}, {i+2, j-1}, {i+1, j+2}, {i+1, j-2},
            {i-2, j+1}, {i-2, j-1}, {i-1, j+2}, {i-1, j-2}};
}
 
int countOnwardMoves(vector<vector<int>> &grid, int i, int j, int n) {
    int count = 0;
    for (auto move : getNextMoves(i, j)) {
        if (isSafe(grid, move.first, move.second, n)) {
            count++;
        }
    }
    return count;
}
 
bool f(vector<vector<int>> &grid, int i, int j, int n, int count) {
    if (count == n * n) {
        grid[i][j] = count;
        display(grid, n);
        return true;
    }
    
    grid[i][j] = count;
    
    vector<pair<int, int>> moves = getNextMoves(i, j);
    sort(moves.begin(), moves.end(), [&](pair<int, int> a, pair<int, int> b) {
        return countOnwardMoves(grid, a.first, a.second, n) < countOnwardMoves(grid, b.first, b.second, n);
    });
    
    for (auto move : moves) {
        if (isSafe(grid, move.first, move.second, n)) {
            if (f(grid, move.first, move.second, n, count + 1)) {
                return true;
            }
        }
    }
    
    grid[i][j] = -1; // backtrack
    return false;
}
 
int main() {
    int n = 8;
int i,j;
cin>>i>>j;
    vector<vector<int>> grid(n, vector<int>(n, -1));
    if (!f(grid, j-1, i-1, n, 1)) {
        cout << "No solution exists." << endl;
    }
    return 0;
}