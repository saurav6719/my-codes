#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> orderHeights(vector<int>& heights, vector<int>& inFronts) {
    int n = heights.size();
    vector<pair<int, int>> people;

    // Combine height and inFront as a pair
    for (int i = 0; i < n; ++i) {
        people.push_back({heights[i], inFronts[i]});
    }

    // Sort people in descending order of height.
    // If heights are equal, sort by increasing inFronts.
    sort(people.begin(), people.end(), [](pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    });

    vector<int> result;

    // Insert each person at the index equal to their inFront count
    for (auto& p : people) {
        result.insert(result.begin() + p.second, p.first);
    }

    return result;
}

int main() {
    vector<int> heights = {5, 3, 2, 6, 1, 4};
    vector<int> inFronts = {0, 1, 2, 0, 3, 2};

    vector<int> result = orderHeights(heights, inFronts);

    cout << "Actual order is: ";
    for (int h : result) {
        cout << h << " ";
    }
    cout << endl;

    return 0;
}