#include<iostream>
#include<vector>
using namespace std;
void f(string &str, int i , string result, vector<string> &li, vector<string> &v){
    if(i == str.size()){
        li.push_back(result);
        return;
    }
    int digit = str[i] - '0';
    if(digit <=1){
        f(str, i+1 , result, li, v);
        return;
    }
    for(int i=0;i<v[digit].size();i++){
        f(str, i+1, result+ v[digit][i] ,li, v );

    }
    return;
}
int main(){
    vector<string> v(10);
    string result = "";
    v.push_back("");
    v.push_back("");
    v.push_back("abc");
    v.push_back("def");
    v.push_back("ghi");
    v.push_back("jkl");
    v.push_back("mno");
    v.push_back("pqrs");
    v.push_back("tuv");
    v.push_back("wxyz");
    string str ="23";
    vector<string> li;
    f(str, 0, result, li , v );
    for(int i=0;i<li.size(); i++){
        cout<<li[i]<<" ";
    }
    return 0;
}
