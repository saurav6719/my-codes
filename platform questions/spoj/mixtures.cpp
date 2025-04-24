#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<cstring>
#include<algorithm>
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
vector<vector<int> > dp;
int color(vector<int> &colours,int i, int j){
    int result = 0;
    for(int k = i;k<=j;k++){
        result =( result % 100 + colours[k] % 100) % 100;
    }
    return result;
}

int f(vector<int> & colours, int i, int j){
    // base case 
    if(i==j) return dp[i][j] = 0; // single colour no mixture
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    for(int k = i; k<j; k++){
        ans = min(ans, (f(colours,i,k) + f(colours,k+1,j) + color(colours,i,k) * color(colours,k+1,j)));
    }
    return dp[i][j] = ans;
}
int fbu(vector<int> colours){
    int n = colours.size();
    for(int len = 2; len<=n; len++){
        for(int i = 0; i<=n-len;i++){
            int j = i+len-1;
            int ans = INT_MAX;
            for(int k = i; k<j; k++){
                ans = min(ans, (dp[i][k] + dp[k+1][j] + color(colours,i,k) * color(colours,k+1,j)));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n-1];
}
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    while(cin>>n){
        dp.clear();
        dp.resize(105, vector<int>(105, 0));
        vector<int> input(n);
        for(int i = 0; i<n; i++){
            cin>>input[i];
        }
        cout<<fbu(input)<<endl;
    }
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