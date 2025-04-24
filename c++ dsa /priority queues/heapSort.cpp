#include<iostream>
#include<queue>
using namespace std;

void max_heapify(vector<int> &v, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && v[left] > v[largest]) {
        largest = left;
    }

    if (right < n && v[right] > v[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(v[i], v[largest]);

        // Recursively heapify the affected sub-tree
        max_heapify(v, n, largest);
    }
}

void heapsort(vector<int> &v) {
    int n = v.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        // Build a max-heap from the vector
        max_heapify(v, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        // Move the current root (maximum) element to the end of the vector
        swap(v[0], v[i]);

        // Call max_heapify on the reduced heap
        max_heapify(v, i, 0);
    }
}
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
    
    for(int i = 0; i< v.size() ; i++){
        cout<< v[i] <<" ";
    }
    cout<< endl;

    heapsort(v);
      
    for(int i = 0; i< v.size() ; i++){
        cout<< v[i] <<" ";
    }
    cout<< endl;


    
}