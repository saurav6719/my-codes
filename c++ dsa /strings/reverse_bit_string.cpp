#include<iostream>
#include<string>
using namespace std;
string reverse(string & s){
    int n = s.size();
    string rev = "";
    while(s.size()!= 0){
        rev += s[n-1];
        s.pop_back();
        reverse(s);
    }
    return rev;

}
int main(){
     string s = "00101001110";
     cout<<reverse(s)<<" ";
}