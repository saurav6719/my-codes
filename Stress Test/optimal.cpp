#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    unordered_map<int, vector<int>> mapA, mapB;
    int maxi = 0;

    // scan from the end
    for (int i = n - 1; i >= 0; --i) {
        // if we've already seen a[i] in mapA, we can stop
        if (mapA.find(a[i]) != mapA.end()) {
            maxi = max(maxi, i + 1);
            break;
        }
        // similarly for b[i] in mapB
        if (mapB.find(b[i]) != mapB.end()) {
            maxi = max(maxi, i + 1);
            break;
        }

        
        // if the two values coincide here, stop
        if (a[i] == b[i]) {
            maxi = max(maxi, i + 1);
            break;
        }

        // if b[i] has appeared as some a[j] (j > i),
        // check all those j’s to see if any gap ≠ 1
        auto itA = mapA.find(b[i]);
        if (itA != mapA.end()) {
            for (int idx : itA->second) {
                if (idx - i != 1) {
                    maxi = max(maxi, i + 1);
                    break;
                }
            }
        }
        {
            // otherwise if a[i] has appeared as some b[j]
            auto itB = mapB.find(a[i]);
            if (itB != mapB.end()) {
                for (int idx : itB->second) {
                    if (idx - i != 1) {
                        maxi = max(maxi, i + 1);
                        break;
                    }
                }
            }
        }


        // record this index under a[i] and b[i]
        mapA[a[i]].push_back(i);
        mapB[b[i]].push_back(i);

    }
    cout << maxi << "\n";
    return 0;
}
