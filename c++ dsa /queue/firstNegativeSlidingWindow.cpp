#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;

    int arr[] = {0,-1,-2,3,4,-5,6,4,7,-8};
    vector<int> ans;
    int n = 10;
    int k = 3;
    for(int i = 0; i< n ; i++){
        if(arr[i] <0) q.push(i);
    }
    for(int i = 0; i< n-k+1; i++){
        while(!q.empty() && q.front() < i){
            q.pop();
        }
        if(q.size() ==0) ans.push_back(0);
        if(q.front() >= i and q.front()< i+k){
            ans.push_back(arr[q.front()]);
        }
        else if(q.front()>= i+k){
            ans.push_back(0);
        }
    }
    
    for(int i = 0; i< ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}