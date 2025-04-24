#include<iostream>
using namespace std;
void skip(string &ans, string original, int index){
    // base case
    if(index == original.size()){
        cout<<ans;
        return;
    }
    char ch = original[index];
    if(ch == 'a') skip(ans, original, index + 1);
    else{
        ans += ch;
        skip(ans, original, index +1);
    }
}
int main(){
    string ans = "";
    string original = "Saurav Kumar";
    skip(ans, original,0);
    return 0;
}