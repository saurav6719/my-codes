#include<iostream>
#include<queue>
using namespace std;
int main(){

    
    vector<int> v;
    v.push_back(9);
    v.push_back(6);
    v.push_back(1);
    v.push_back(19);
    v.push_back(3);
    v.push_back(2);
    v.push_back(8);
    v.push_back(12);
    v.push_back(5);
    priority_queue<int> maxhp(v.begin(), v.end());



    // printing the heap
    while (!maxhp.empty()) {
        std::cout << maxhp.top() << " ";
        maxhp.pop();
    }

    std::cout << std::endl;
    
    
}