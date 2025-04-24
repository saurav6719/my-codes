#include<iostream>
#include<string>
using namespace std;
string f(string &str, int idx, int n){
    if(idx == n){
        return "";
    }
    string curr ="";
    curr += str[idx];
    string ans= (str[idx] == 'a' ? "" : curr) + f(str,idx+1,n);
    return ans;
}
int main(){
    string s="abcax";
    
    std :: cout<<s<<endl<<f(s,0,5);
    
    return 0;
}