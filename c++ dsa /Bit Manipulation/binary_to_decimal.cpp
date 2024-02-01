#include<iostream>
using namespace std;

int btd(string &s){
    int n  = s.size();
    int result = 0;
    for(int i = n-1; i>=0; i--  ){
        char ch = s[i];
        int x = n - i- 1;
        int num = ch -'0';
        result += num * (1<<x);
    }
    return result;
}
int main(){
    string s = "100001111";
    cout<<btd(s)<<endl;
    return 0;
}