#include<iostream>
using namespace std;
int main(){
    int a;
    int b;
    cin>>a;
    cin>>b;
    int first = 0;
    int draw= 0;
    int second = 0;
    for(int i = 1;i<=6;i++){
        if(abs(i-a) <abs(i-b)){ // a is closer
            first++;
        }
        else if(abs(i-a) == abs(i-b)){ // draw
            draw++;
        }
        else{
            second++;
        }
    }
    cout<<first<<" "<<draw<<" "<<second; 
    return 0;
}