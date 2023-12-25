#include<iostream>
#include<stack>
#include<string>
using namespace std;
string answer(string val1  , string val2, char ch){
    string s= "";
    s += val1;
    s += val2;
    s.push_back(ch);
    return s;
}

int main(){
    string s = "-/*+79483";
    cout<<"Prefix statement : " <<s<<endl;
    stack<string> val;
    int x = s.size();
    for(int i = x-1; i>= 0; i--){
        if((s[i]) >= 48 and s[i] <= 57){
            val.push(to_string(s[i] -48));
        }
        else {
            string val1 = val.top();
            val.pop();
            string val2= val.top();
            val.pop();
            string ans = answer(val1, val2, s[i]);
            val.push(ans);
        }
    }
    cout<<"postfix statement : "<<val.top()<<endl;
    return 0;
}