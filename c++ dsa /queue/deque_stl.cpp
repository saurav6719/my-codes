#include<iostream>
#include<deque>
using namespace std;
void display(deque<int> &myDeque){
    for(int i = 0; i< myDeque.size(); i++){
        cout<< myDeque[i]<<" ";
    }
    cout<<endl;
}

int main(){
    deque<int> q;
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    display(q);
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    q.pop_back();
    display(q);
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    return 0;
}