#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Helper function to check if we can partition the cake with max tastiness for Alice's piece as `maxAlice`
bool canPartition(const vector<int>& tastiness, int n, int m, int v, long long maxAlice) {
    long long currentSum = 0;
    int requiredPieces = 0;

    for (int i = 0; i < n; ++i) {
        currentSum += tastiness[i];
        
        if (currentSum >= v) {  // A piece for a creature
            ++requiredPieces;
            currentSum = 0;  // Start a new piece
        }
        
        if (requiredPieces >= m) {
            // Remaining sum for Alice should be <= maxAlice
            long long remainingSum = accumulate(tastiness.begin() + i + 1, tastiness.end(), 0LL);
            return remainingSum <= maxAlice;
        }
    }
    
    return false;  // Not enough pieces for each creature
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, v;
        cin >> n >> m >> v;

        vector<int> tastiness(n);
        for (int i = 0; i < n; ++i) {
            cin >> tastiness[i];
        }

        long long totalSum = accumulate(tastiness.begin(), tastiness.end(), 0LL);
        
        // Binary search for the maximum tastiness Alice can achieve
        long long left = 0, right = totalSum;
        long long answer = -1;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            
            if (canPartition(tastiness, n, m, v, mid)) {
                answer = mid;  // Update answer to mid if feasible
                left = mid + 1;  // Try for a larger tastiness
            } else {
                right = mid - 1;  // Try for a smaller tastiness
            }
        }

        cout << answer << endl;
    }

    return 0;
}
