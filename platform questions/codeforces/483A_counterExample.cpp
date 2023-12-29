#include<iostream>
#define ll long long int
using namespace std;
int main(){
ll l;
cin>>l;
ll r;
cin>>r;
ll a= -1;
if(l % 2 == 0){
    a = l;
}
else a = l+1;
if(r-l < 2 ) cout<<"-1";
else if(a+2 > r) cout<<"-1";
else{
    cout<< a<<" "<<a+1<<" "<<a+2;
}
    return 0;
}