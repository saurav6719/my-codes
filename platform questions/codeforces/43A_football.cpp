#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    int teamA= 0;
    int teamB = 0;
    string str = input[0];
    string str2;
    for(int i = 0; i<n; i++){
        if(input[i] == str) teamA++;
        else{
            str2 = input[i];
            teamB++;
        }
    }

    if(teamA>teamB) cout<<str;
    else cout<<str2;

    return 0;
}