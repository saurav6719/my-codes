#include<iostream>
using namespace std;
void rev(string &str, int start, int end){
    if(start>= end) return;
    swap(str[start], str[end]);
    return rev(str,start+1,  end-1);
}
int main(){
    string str = "saurav";
    int n = str.size();
    rev(str, 0, n-1);
    cout<<str;
    return 0;
}