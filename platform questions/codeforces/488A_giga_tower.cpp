#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
bool lucky(ll n) {
    n = abs(n);
    while (n != 0 && n % 10 != 8) {
        n /= 10;
    }
    return n % 10 == 8;
}
int main(){
    ll n;
    cin>>n;
    for(int i = 1;i<=20;i++){  // why 1 to 20 -> there will be atleast one 8 in every 10 consecutive number but for -8 next lucky is + 8 which is 16 far away . so for ease we took 1 to 20
        if(lucky(n+i)){
            cout<<i<<endl;
            break;
        }
        
    }
    return 0;
}