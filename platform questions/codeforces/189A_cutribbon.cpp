#include<iostream>
#include<vector>
#include<unordered_set>
#define mn(a,b,c)  min(a,min(b,c));
using namespace std;
int main(){
    int n;
    int a,b,c;
    cin>>n>>a>>b>>c;
    vector<int> dp(n+5,0);
    int k = mn(a,b,c);
    dp[k] = 1;

    for(int i = k+1; i<n+5; i++){
        if(i%a == 0) dp[i] = max(dp[i], i/a);
        if(i%b == 0) dp[i] = max(dp[i], i/b);
        if(i%c == 0) dp[i] = max(dp[i], i/c);
        for(int j = 0; j<i;j++){
            if(dp[j] != 0 and dp[i-j]!=0) dp[i] = max(dp[i], dp[j]+dp[i-j]);
        }
    }

    cout<<dp[n];
    return 0;
}