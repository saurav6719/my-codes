#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> input(m);
    for(int i = 0; i<m; i++){
        int a;
        cin>>a;
        input[i] =a;
    }
    sort(input.begin(), input.end());
    int i = 1;
    int j = n;
    int diff = input[j-1] - input[0];
    while(j<m){
        if(input[j] - input[i] < diff){
            diff = input[j] - input[i];
        }
        i++;
        j++;
    }
    cout<<diff;

    return 0;
}