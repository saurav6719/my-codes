#include<iostream>
using namespace std;
int main(){
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    bool flag = false;
    for(int i = 0; i< s1.size(); i++){
        if(int(s1[i]) < 95){ // uppercase
            s1[i] = char(int(s1[i]) + 32);
        }
    }
    for(int i = 0; i< s2.size(); i++){
        if(int(s2[i]) < 95){ // uppercase
            s2[i] = char(int(s2[i]) + 32);
        }
    }
    for(int i = 0; i< s1.size(); i++){
        if(int(s1[i])< int(s2[i])) {
            flag = true;
            cout<<"-1";
            break;
        }
        if(int(s1[i])> int(s2[i])) {
            flag = true;
            cout<<"1";
            break;
        }
    }
    if(!flag) cout<<"0";

    
    return 0;
}