#include<iostream>
#include<string>
#include<unordered_set>
#include<unordered_set>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    unordered_set<char> st;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '{' or s[i] =='}' or s[i] ==',' or s[i] == ' ') continue;
        else{
            st.insert(s[i]);
        }
    }
    cout<<st.size()<<endl;
    return 0;
}