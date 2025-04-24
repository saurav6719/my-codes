#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
void f(string s, int i ){
    // base case
    if(i == s.size()-1){
        cout<<s<<endl;
        return;
    }
    unordered_set<char> st;

    for(int idx = i; idx < s.size(); idx++){
        if(st.count(s[idx])) continue;
        st.insert(s[idx]);
        swap(s[idx], s[i]);
        f(s,i+1);
        swap(s[idx], s[i]);    // backtracking step
    }

}
int main(){
    string s = "aba";
    f(s,0);
    return 0;
}