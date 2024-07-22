
#include<bits/stdc++.h>

using namespace std;

// Define an interval as a tuple (start, end)
typedef tuple<int, int> Interval;

// Comparator to sort intervals by their end time
bool compareEnd(const Interval &a, const Interval &b) {
    return get<1>(a) < get<1>(b);
}

// Comparator to sort intervals by their start time
bool compareStart(const Interval &a, const Interval &b) {
    return get<0>(a) < get<0>(b);
}

int countNonOverlappingTriplets(vector<Interval> &intervals) {
    int n = intervals.size();
    if (n < 3) return 0; // If less than 3 intervals, return 0

    // Sort intervals by end time
    sort(intervals.begin(), intervals.end(), compareEnd);

    // Create prefix and suffix maximum arrays
    vector<int> prefixMax(n, 0), suffixMax(n, 0);
    prefixMax[0] = 1;
    suffixMax[n - 1] = 1;

    for (int i = 1; i < n; ++i) {
        prefixMax[i] = max(prefixMax[i - 1], i + 1);
    }

    for (int i = n - 2; i >= 0; --i) {
        suffixMax[i] = max(suffixMax[i + 1], n - i);
    }

    // Count the number of valid triplets
    int count = 0;

    for (int i = 0; i < n; ++i) {
        int end_i = get<1>(intervals[i]);
        // Find the maximum number of intervals that end before intervals[i] starts
        int left = lower_bound(intervals.begin(), intervals.end(), Interval(0, end_i), compareEnd) - intervals.begin() - 1;

        if (left >= 0 && prefixMax[left] >= 1) {
            int start_i = get<0>(intervals[i]);
            // Find the maximum number of intervals that start after intervals[i] ends
            int right = upper_bound(intervals.begin(), intervals.end(), Interval(start_i, INT_MAX), compareStart) - intervals.begin();

            if (right < n && suffixMax[right] >= 1) {
                count += prefixMax[left] * suffixMax[right];
            }
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<Interval> intervals(n);
    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        intervals[i] = make_tuple(start, end);
    }

    cout << countNonOverlappingTriplets(intervals) << endl;

    return 0;
}
