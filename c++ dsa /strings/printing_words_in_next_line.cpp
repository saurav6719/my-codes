#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="   saurav    is    a  good boy ";
    string str;
    for(int i=0;i<s.size();i++){
        
        if(s[i]==' ' and s[i+1]!=' '){
            str.push_back(s[i+1]);
        }
        else if(s[i]!=' ' and s[i+1]!=' '){
            str.push_back(s[i+1]);
        }
        else if(s[i]!=' ' and s[i+1]==' '){
            
            cout<<str<<endl;
            str.clear();
        }
        

    }
    cout<<str;
    
    return 0;
}