#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
// link -> https://atcoder.jp/contests/dp/tasks/dp_i
double dp[3005][3005];
double f(vector<double> & p, int i, int x){
    //base case
    if(x==0) return 1;
    if(i==-1) return 0;
    if(dp[i][x] > -0.9) return dp[i][x];
    return dp[i][x] = (((f(p,i-1,x-1)) * p[i]) + ((f(p,i-1,x)) * (1-p[i])));
}

void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    vector<double> prob(n);
    for(int i = 0; i<n; i++){
        cin>>prob[i];
    }
    int x = (n+1)/2;
    int i = n-1;
    cout<<fixed<<setprecision(9)<<f(prob,i,x);
}

int32_t main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        memset(dp,-1,sizeof dp);
        solve();
    }
return 0;
}