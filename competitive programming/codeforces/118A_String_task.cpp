#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    string ans= "";
    for(int i = 0; i< s.size(); i++){
        if(s[i] == 'A' or s[i]== 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U' or s[i] == 'Y') continue;
        else if(s[i] == 'a' or s[i]== 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'y' ) continue;
        else if(int(s[i]) >=97) {
            ans+= '.';
            ans+= s[i];
        }
        else if(int(s[i]) <=90 and int(s[i]) >= 65) {
            ans+= '.';
            ans+= int(s[i] + 32);
        }
    }
    s = ans;
    cout<<s;

    return 0;
}