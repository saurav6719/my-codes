#include<iostream>
#include<vector>
#include<string>
#define ll long long int 
using namespace std; 
vector<ll> dp;
int f(string & str, int i){
    // base case
    if(i<= 0) return 1;
    if(dp[i] != -1) return dp[i];
    ll ans = 0; 
    if(str[i] - '0' > 0){
        ans += f(str,i-1);
    }
    if((str[i-1] - '0') > 0 and ((str[i-1] - '0') * 10 + (str[i] - '0')) <= 26){
        ans += f(str,i-2);
    }
    return dp[i] = ans;
}
int main(){
    string n;
    cin>>n;
    while(n[0] != 0){
        dp.clear();
        dp.resize(5005,-1);
        cout<<f(n,n.size()-1);
        cout<<"\n";
        cin>>n;
    }
    return 0;
}