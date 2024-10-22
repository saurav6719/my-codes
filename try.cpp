#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include<climits>
using namespace std;

long long mod=1000000007;

int main(){
    long long n,x;
    cin>>n>>x;

    vector<long long>coins(n);
    for(long long i=0;i<n;i++)
        cin>>coins[i];

    sort(coins.begin(),coins.end());
    
    int dp[1000001];

    for(int i = 0; i<=1000000; i++){
        dp[i] = 0;
    }
    
    dp[0]=1;

    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-coins[j]>=0){
                dp[i] += dp[i-coins[j]];
                dp[i] %= mod;
            }
            else break;
        }
    }
    cout<<dp[x]%mod<<endl;
    return 0;
}