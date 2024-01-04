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

int fbu(string &str, int i ){
    dp.resize(5005, 0);
    dp[0] = (str[0] != '0');  // if first character is 0 then 0 else 1
    if(str.size() > 1){
        if(str[1] != '0') dp[1] += dp[0];
        if((str[0] - '0')>0 and (((str[0] - '0') * 10) + (str[1] -'0')) <= 26) dp[1]++;
    }

    for(int i = 2; i< str.size(); i++){
        ll ans = 0;
        if(str[i] - '0' > 0){
        ans += dp[i-1];
        }
        if((str[i-1] - '0') > 0 and ((str[i-1] - '0') * 10 + (str[i] - '0')) <= 26){
            ans += dp[i-2];
        }
        dp[i] = ans;

    }

    return dp[str.size() -1 ];
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