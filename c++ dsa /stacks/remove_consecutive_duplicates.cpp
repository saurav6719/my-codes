#include<iostream>
#include<stack>
using namespace std;
string updated(string &s){
    stack<char> st;
    for(int i =0 ;i<s.size();i++){
        if(st.empty()) st.push(s[i]);
        else if(s[i] == st.top()) continue;
        else if(s[i] != st.top()) st.push(s[i]);    
    }
    s.clear();
    while(st.size() != 0){
        s.push_back(st.top());
        st.pop();
    }
    reverse(s.begin(), s.end());
    return s;
}
int main(){
    string s = "aaabbcddaabffg";
    cout<<updated(s);
    return 0;
}
