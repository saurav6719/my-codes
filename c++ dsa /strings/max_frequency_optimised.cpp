#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    vector<int> v(26,0);
    string s="leetcode";
    for(int i=0;i<s.size();i++){
        v[s[i]-97]++;

    }
    int count=-1;
    for(int i=0;i<v.size();i++){
        if(count<v[i]){
            count=v[i];
        }
    }
    for(int i=0;i<v.size();i++){
        if(v[i]==count){
            cout<<char(i+97)<<" "<<count;
        }
    }
    
    return 0;
}