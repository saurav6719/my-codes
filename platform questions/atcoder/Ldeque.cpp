#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
vector<vector<int> >dp;
int f(vector<int> &input, int i, int j){
    if(i==j) return input[i];
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = max(input[i] - f(input,i+1,j) , input[j] - f(input,i,j-1));
}
int fbu(vector<int> &input, int n){
    //base case
    for(int i = 0; i<n; i++){
        dp[i][i] = input[i];
    }
    for(int len = 2; len<=n ; len++){
        for(int i = 0; i <= n-len;i++){
            int j = i+ len -1;
            dp[i][j] = max(input[i] - dp[i+1][j] , input[j] - dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n ; i++){
        cin >> input[i];
    }
    dp.clear();
    dp.resize(3005,vector<int> (3005,0));
    cout<<fbu(input,n);

}
int32_t main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}