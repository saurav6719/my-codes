#include<iostream>
#include<queue>
using namespace std;

int main(){
    
    int arr[]={2,3,7,1,9,-6,11};
    priority_queue<int> pq(arr, arr+7);
    while(pq.size()!= 0){
        cout<<pq.top()<<" ";
        pq.pop();
    }

}
