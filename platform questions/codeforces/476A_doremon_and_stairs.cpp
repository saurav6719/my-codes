#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    int answer;
    int x = n/2;
    int y = n%2;
    if(n<m) answer = -1;
    else if(x % m == 0 and y == 0) answer = x;
    else{
        int a = x / m;
        int b = a+1;
        answer = m*b;
    }
    cout<<answer;
    return 0;
}