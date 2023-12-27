#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;

    vector<int> heights(n);
    for(int i =0 ; i<n ; i++){
        int a;
        cin>>a;
        heights[i] = a;
    }

    int max = INT_MIN;
    int maxidx = -1;
    int min = INT_MAX;
    int minidx = -1;

    for(int i = 0; i< n ; i++){
        if(heights[i] > max){
            max = heights[i];
            maxidx = i;
        }
        if(heights[i] <= min){
            min = heights[i];
            minidx = i;
        }
    }
    int ans= 0;
    ans += (n-1) - (minidx);
    ans += maxidx;
    if(maxidx > minidx) ans--;
    cout<<ans;

    return 0;
}