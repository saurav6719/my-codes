#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int coo = 0;
    int cot = 0;
    int coth = 0;
    for(int i = 0 ; i < s.size(); i++){
        if(s[i] == '1') coo++;
        if(s[i] == '2') cot++;
        if(s[i] == '3') coth++;
    }
    string s1 ="";
    for(int i = 0; i<coo; i++){
        s1 += '1';
        s1 += '+';
    }
    for(int i = 0; i<cot; i++){
        s1 += '2';
        s1 += '+';
    }
    for(int i = 0; i<coth; i++){
        s1 += '3';
        s1 += '+';
    }
    s1.pop_back();
    cout<<s1;
    return 0;
}