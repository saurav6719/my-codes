#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="aaaaabbb";
    int max_count=0;
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        int count=0;
        for(int j=i;j<s.size();j++){
            if(s[i]==s[j]){
                count ++;
                
            }
        }
        max_count=max(count,max_count);
    }
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        int count=0;
        for(int j=i;j<s.size();j++){
            if(s[i]==s[j]){
                count ++;
                
            }
        }
        if(count==max_count){
            cout<<ch<<" "<<max_count<<endl;
        }
    }
    
    return 0;
}
