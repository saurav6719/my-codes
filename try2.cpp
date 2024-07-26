#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> findValidSubstrings(const string& s) {
    int n = s.length();
    unordered_map<int, int> prefix_count;
    vector<pair<int, int>> valid_substrings;

    // Initialize prefix sum and hash map
    int prefix_sum = 0;
    prefix_count[0] = 1; // To handle the case when prefix_sum is zero

    // Compute prefix sums and find valid substrings
    for (int i = 0; i < n; ++i) {
        // Update the prefix sum
        prefix_sum += (s[i] == '1') ? 1 : -1;

        // If this prefix sum has been seen before
        if (prefix_count.find(prefix_sum) != prefix_count.end()) {
            // We need to find the starting indices
            int count = prefix_count[prefix_sum];
            int start_index = i + 1 - count; // Start from the first occurrence of this prefix sum

            // Record all valid substrings
            for (int j = 0; j < count; ++j) {
                valid_substrings.emplace_back(start_index + j + 1, i + 1); // Adjusting to 1-based indexing
            }
        }

        // Update the count of this prefix sum
        prefix_count[prefix_sum]++;
    }

    return valid_substrings;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();

    vector<pair<int, int>> result = findValidSubstrings(s);

    int cnt= 0;

    for(auto ele : result){
        int start = ele.first;
        int end = ele.second;

        int xx = n-end+1;
        int yy = start;
        cnt += xx*yy;
    }
    for (const auto& p : result) {
        cout << p.first << " " << p.second << endl;
    }

    // cout<<cnt<<endl;

    return 0;
}
