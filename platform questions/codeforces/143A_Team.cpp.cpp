#include<iostream>
using namespace std;
int main(){
    int output = 0;
    int n;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        int ans= 0;
        if(a == 1) ans++;
        if(b == 1) ans++;
        if(c == 1) ans++;
        if(ans >=2) output++;
    }
    cout<<output;
    return 0;
}