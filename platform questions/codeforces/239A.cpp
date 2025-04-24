#include<iostream>
#include<vector>
using namespace std;
int main(){
    int y;
    int k;
    int n;
    cin>>y>>k>>n;
    int y_copy = y;
    int num = y_copy % k;
    num = k - num;
    int first = y+num;
    bool flag = true;
    if(first > n) flag = false;
    if(!flag)cout<<"-1";
    else{
        while(first <= n){
        cout <<first - y <<" ";
        first += k;
    }
    }

    return 0;
}