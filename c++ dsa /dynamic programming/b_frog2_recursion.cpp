#include<iostream>
#include<vector>
using namespace std;
vector<int> heights;
int k;
int f(int i ){ 
    // base case
    if(i >= heights.size()) return INT_MAX; // aage se piche nhi aa skte kabhi
    if(i == heights.size() -1) return 0; // last stone se last stone ka no cost
    int ans = INT_MAX;
    // recurrence relation
    for(int j = 1; j<= k ; j++){
        if(i+j >= heights.size()) break;
        ans = min(ans, abs(heights[i] - heights[i+j] )  + f(i+j));
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    heights.resize(n);
    cin>>k;
    for(int i = 0; i < n;i++){
        cin>>heights[i];
    }
    cout<<f(0);
    return 0;
}