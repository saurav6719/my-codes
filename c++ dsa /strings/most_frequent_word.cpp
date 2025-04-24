#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    stringstream ss(s);
    vector <string> v;
    string temp;
    while(ss>>temp){
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    int mx=0;
    for(int i=0;i<v.size()-1;i++){
        int count=1;
        if(v[i+1]==v[i]){
            count++;
        }
        mx=max(mx,count);
    }
    for(int i=0;i<v.size()-1;i++){
        int count=1;
        if(v[i+1]==v[i]){
            count++;
        }
        if(count==mx){
            cout<<v[i]<<" "<<mx<<endl;
        }
    }

    return 0;

}