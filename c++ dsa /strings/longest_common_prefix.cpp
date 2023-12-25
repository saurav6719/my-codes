#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    vector <string> strs;
    strs.push_back("car");
    strs.push_back("race");
    strs.push_back("racecar");

    sort(strs.begin(),strs.end());
    int n= strs.size();
    string s="";
    bool flag= false;
    string first=strs[0];
    string last=strs[n-1];

    for(int i=0;i<strs[0].size();i++){
        if(first[i]==last[i]){
            s+=first[i];
        }
        else{
            flag=true;
            cout<<s;
            break;
        }

    }
    if(flag == false){
        cout<<s;
    }

    return 0;
}