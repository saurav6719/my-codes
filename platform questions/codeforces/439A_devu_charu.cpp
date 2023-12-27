#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, d;
    cin>>n>>d;
    vector<int> song(n);
    for(int i = 0; i< n ; i++){
        int a; 
        cin>>a;
        song[i] = a;
    }
    int answer;
    int breaks = n-1;
    int breaktime = breaks * 10;
    int songtime = d - breaktime;
    int sum = 0;
    for(int i = 0 ; i< n ; i++){
        sum += song[i];
    }
    if(sum > songtime) answer = -1;
    else {
        answer = (d - sum) / 5;
    }
    cout<<answer;
    return 0;
}