#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans = 0;;
    for(int i = 0; i<n ; i++){
        string s;
        cin>>s;
        if(s== "++X" or s=="X++") ans++;
        if(s== "--X" or s=="X--") ans--;
    }
    cout<<ans;
    return 0;
}