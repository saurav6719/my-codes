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

};
int main(){
    maxHeap hp;
    hp.push(105);
    hp.push(12);
    hp.push(22);
    hp.push(10);
    hp.push(8);
    hp.push(8);
    hp.push(33);
    hp.push(3);
    hp.push(5);
    hp.push(7);
    hp.push(200);
    hp.push(101);
    hp.push(11);
    hp.push(100);
    hp.push(9);
    hp.push(1);
    hp.push(20);
    hp.push(6);
    hp.push(4);
    hp.push(6);

    hp.display();
    //cout<<hp.peek();
    hp.pop();
    hp.display();

    hp.delete_custom_index(2);
    hp.display();
    
    return 0;
}