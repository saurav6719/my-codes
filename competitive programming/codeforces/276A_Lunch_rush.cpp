#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int n;
    int k;
    cin>>n;
    cin>>k;
    vector<pair<int,int> > input(n);
    for(int i = 0; i<n ; i++){
        cin>>input[i].first>>input[i].second;
    }
    int joy = INT_MIN;
    for(int i =0; i<n ;i++){
        int current_joy;
        if(input[i].second > k){
            current_joy = input[i].first - (input[i].second - k);
        }
        else current_joy = input[i].first;
        joy = max(joy,current_joy);
    }

    cout<<joy;

    return 0;
}