#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="ADSHKSSKJHC";
    for(int i=0;i<s.length();i++){
        bool flag=true;
        for(int j=0;j<s.length()-1-i;j++){

            if(s[j]>s[j+1]){
                swap(s[j],s[j+1]);
                flag = false;
            }


        }
        if(flag == true){
            break;
        }
    }
    cout<<s;
    
    return 0;
}
