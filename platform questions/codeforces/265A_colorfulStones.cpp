#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    string t;
    cin>>t;
    int i = 0;
    int j = 0;
    while(j<t.size()){
        if(t[j] == s[i]) i++;
        j++;
    }

    cout<<i+1;
    return 0;
}