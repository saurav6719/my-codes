#include<iostream>
#define ll long long int
using namespace std;
int main(){
    ll n,m;
    cin>>n>>m;
    ll a;
    cin>>a;
    ll ans = 1;
    if(n%a == 0){
        ans *= n/a;
    }
    else{
        ans *= (n/a) + 1;
    }
    if(m%a == 0){
        ans *= m/a;
    }
    else{
        ans *= (m/a) + 1;
    }
    cout<<ans;

    return 0;
}