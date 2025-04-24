#include<iostream>
#include<vector>
using namespace std;
class maxHeap{
    void upheapify(int child){
        while(child >=0){
            int parent = (child - 1) / 2;
            if(hp[child] > hp[parent]){
                swap(hp[child], hp[parent]);
                child = parent;
            }
            else break;
        }
    }

    void downheapify(int index){
        while(index < hp.size()){
            int left_child = 2 * index + 1;
            int right_child = 2 * index + 2;
            if(left_child > hp.size()) break; // leaf node
            int maxEle = index;
            if(hp[left_child] > hp[maxEle]) maxEle = left_child;
            if(right_child < hp.size() and hp[right_child] > hp[maxEle]) maxEle = right_child;
            if(maxEle != index){
                swap(hp[maxEle], hp[index]);
                index = maxEle;
            }
            else break; // already a heap
        }
    }
    vector<int> hp;
    public:
    
    void push(int element){
        hp.push_back(element);
        upheapify(hp.size()-1);
        //time complexity = O(log n)
    }
    
    bool empty(){
        return hp.size()==0;
    }
    void pop(){
        if(empty()) return;
        swap(hp[0], hp[hp.size()-1]);
        hp.pop_back();
        if(!empty()){
        downheapify(0);
        }
        //time complexity = O(log n)
    }
    void display(){
        for(int i = 0; i<hp.size(); i++){
            cout<<hp[i]<<" ";
        }
        cout<<endl;
    }
    int peek(){
        return hp[0];
        //time complexity = O(1);
    }
    void delete_custom_index(int index){
        hp[index] = INT_MAX;
        upheapify(index);
        pop();
    }
    maxHeap(vector<int> v){
        hp = v;
        for(int i= 1; i<hp.size();i++){
            upheapify(i);
        }
    }
};
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

    maxHeap hp(v);

    hp.push(100);
    hp.display();
    
    
    return 0;
}