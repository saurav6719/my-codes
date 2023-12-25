#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    string ans ="";
    bool flag = true; // word nhi print kiya hu 
    int i = 0;
    while(i<s.size()){
        if(s[i]== 'W' and s[i+1] == 'U' and s[i+2] == 'B'){
            i = i+3;
            if(flag == true) ans+= " ";
            flag = false;
        }
        else{
            flag = true; // word print hua
            ans += s[i];
            i++;
        }

    }
    cout<<ans;
    return 0;
}