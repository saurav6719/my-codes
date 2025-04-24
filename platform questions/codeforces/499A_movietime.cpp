#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<vector<int> > input(n,vector<int>(2));
    for(int i = 0; i<n ;i++){
        for(int j = 0; j <2; j++){
            cin>>input[i][j];
        }
    }
    int current = 1;
    int count = 0;

    for(int i = 0; i<n; i++){
        int start = input[i][0];
        int skip =( start - current ) / x; 
        current += skip * x;
        count += input[i][1] - current + 1;
        current = input[i][1] + 1;
    }
    cout<<count;


    return 0;
}