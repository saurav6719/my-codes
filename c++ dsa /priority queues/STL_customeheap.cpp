#include <iostream>
#include <queue>
#include <vector>

// Define a custom comparison function to implement a min-heap
class CustomComparator { // hum aisha heap bnna chah rhe jisme element * 2 ki value maximum ho 
    public:
    bool operator()(double p1, double p2) {
        double r1 = p1 * 2;
        double r2 = p2 * 2;
        return r1 < r2;
    }
};

int main() {
    // Create a priority queue with the custom comparator
    std::priority_queue<double, std::vector<double>, CustomComparator> hp;

    // Push elements into the min-heap
    hp.push(10);
    hp.push(20);
    hp.push(-19);
    hp.push(19);
    hp.push(3);
    hp.push(2);
    hp.push(8);
    hp.push(12);
    hp.push(5);

    // The top element is the smallest element in the min-heap
    std::cout << "Top element: " << hp.top() << std::endl;

    // Pop elements from the min-heap
    while (!hp.empty()) {
        std::cout << hp.top() << " ";
        hp.pop();
    }
    std::cout << std::endl;

    return 0;
}
