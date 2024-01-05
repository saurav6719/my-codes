#include<iostream>
#include<vector>
using namespace std;
int main(){
    string str;
    cin>>str;
    int index = -1;
    for(int i = 0; i<str.size();i++){
        if(str[i] == '^') {
        index = i;
        break;
        }
    }
    int left = 0;
    int right = 0;

    for(int i = 0; i<index;i++){
        if(str[i] != '=') {
            left +=(str[i] - '0') * (index-i);
        }
    }

    for(int i = index+1; i<str.size();i++){
        if(str[i] != '=') {
            right +=(str[i] - '0') * (i - index);
        }
    }

    if(left == right) cout<<"balance";
    else if(left>right) cout<<"left";
    else cout<<"right";
    return 0;
}
