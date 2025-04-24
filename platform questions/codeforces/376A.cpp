#include<iostream>
#define ll long long int
#include<vector>
using namespace std;
int main(){
    string str;
    cin>>str;
    ll index = -1;
    for(int i = 0; i<str.size();i++){
        if(str[i] == '^') {
        index = i;
        break;
        }
    }

    ll sum = 0;
    

    for(int i = 0; i<str.size();i++){
        if(str[i] != '=') {
            sum +=(str[i] - '0') * (i-index);
        }
    }

    if(sum == 0) cout<<"balance";
    else if(sum<0) cout<<"left";
    else cout<<"right";
    return 0;
}
