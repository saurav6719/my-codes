#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

class Players {
    private:
        vector<int> parents;
        vector<int> sizes;
        vector<int> points;
        vector<int> extra_points;
    public:
        Players(int size) : parents(size), sizes(size, 1),
                            points(size), extra_points(size) {
            for (int i = 0; i < size; i++) {
                parents[i] = i;
            }
        }

        int get_ultimate(int n) {
            return parents[n] == n ? n : get_ultimate(parents[n]);
        }

        int get_points(int n) {
            int amt = points[n];
            if (parents[n] == n) {
                return amt;
            }
            amt += get_points(parents[n]) - extra_points[n];
            return amt;
        }

        void add_points(int n, int p) {
            int top = get_ultimate(n);
            points[top] += p;
        }

        bool link(int n1, int n2) {
            n1 = get_ultimate(n1);
            n2 = get_ultimate(n2);
            if (n1 == n2) {
                return false;
            }
            if (sizes[n1] < sizes[n2]) {
                std::swap(n1, n2);
            }
            sizes[n1] += sizes[n2];
            parents[n2] = n1;
            extra_points[n2] = points[n1];
            return true;
        }
};

/**
 * https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
 * 3 6
 * add 1 100
 * join 1 3
 * add 1 50
 * get 1
 * get 2
 * get 3 should output 150, 0, and 50, each on a new line
 */
int main() {
    int node_num;
    int query_num;
    std::cin >> node_num >> query_num;
    Players players(node_num + 1);
    for (int q = 0; q < query_num; q++) {
        std::string type;
        std::cin >> type;
        if (type == "get") {
            int n;
            std::cin >> n;  
            cout << players.get_points(n) << endl;
        } else if (type == "add") {
            int n;
            int points;
            std::cin >> n >> points;
            players.add_points(n, points);
        } else if (type == "join") {
            int a;
            int b;
            std::cin >> a >> b;
            players.link(a, b);
        }
    }
}