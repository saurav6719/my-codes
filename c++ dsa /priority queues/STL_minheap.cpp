#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int, vector<int>, greater<int> > v;
    v.push(9);
    v.push(6);
    v.push(1);
    v.push(19);
    v.push(3);
    v.push(2);
    v.push(8);
    v.push(12);
    v.push(5);
    
    cout<<v.top()<<endl;
    
}