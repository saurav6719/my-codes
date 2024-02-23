#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a node in the segment tree
struct Node {
    int frequency;
    int element;
};

// Function to build the segment tree
void buildSegmentTree(vector<Node>& segmentTree, const vector<int>& arr, int low, int high, int pos) {
    if (low == high) {
        segmentTree[pos].frequency = 1;
        segmentTree[pos].element = arr[low];
        return;
    }

    int mid = (low + high) / 2;
    buildSegmentTree(segmentTree, arr, low, mid, 2 * pos + 1);
    buildSegmentTree(segmentTree, arr, mid + 1, high, 2 * pos + 2);

    if (segmentTree[2 * pos + 1].frequency >= segmentTree[2 * pos + 2].frequency) {
        segmentTree[pos] = segmentTree[2 * pos + 1];
    } else {
        segmentTree[pos] = segmentTree[2 * pos + 2];
    }
}

// Function to query the segment tree for maximum frequency in a range
Node querySegmentTree(const vector<Node>& segmentTree, int qlow, int qhigh, int low, int high, int pos) {
    if (qlow > high || qhigh < low) {
        Node nullNode = {0, -1};
        return nullNode;
    }

    if (qlow <= low && qhigh >= high) {
        return segmentTree[pos];
    }

    int mid = (low + high) / 2;
    Node left = querySegmentTree(segmentTree, qlow, qhigh, low, mid, 2 * pos + 1);
    Node right = querySegmentTree(segmentTree, qlow, qhigh, mid + 1, high, 2 * pos + 2);

    if (left.frequency >= right.frequency) {
        return left;
    } else {
        return right;
    }
}

int findMaxOccurringElement(const vector<int>& arr, const vector<pair<int, int> >& queries) {
    int n = arr.size();

    // Build the segment tree
    vector<Node> segmentTree(4 * n);
    buildSegmentTree(segmentTree, arr, 0, n - 1, 0);

    int maxElement = -1;
    int maxFrequency = 0;

    for (const auto& query : queries) {
        int qlow = query.first - 1;
        int qhigh = query.second - 1;

        Node result = querySegmentTree(segmentTree, qlow, qhigh, 0, n - 1, 0);

        if (result.frequency > maxFrequency) {
            maxFrequency = result.frequency;
            maxElement = result.element;
        }
    }

    return maxFrequency;
}

int main() {
    // Example usage with multiple queries
    int n,q;
    cin>>n>>q;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    vector<pair<int,int> >queries;
    while(q--){
        int l,r;
        cin>>l>>r;
        pair<int,int> pp;
        pp.first = l;
        pp.second = r;
        queries.push_back(pp);
        int result = findMaxOccurringElement(input, queries);
        cout << "The element occurring with the maximum frequency in each query is: " << result << endl;
    }


    return 0;
}
