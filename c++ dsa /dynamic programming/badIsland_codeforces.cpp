#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<cstring>
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
long double dp[105][105][105];
long double fr(int r, int s, int p){
    //base case
    
    if(r==0) return 0.0;
    if(s==0) return 0.0;
    if(p==0) return 1.0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];
    long double total = r*s + s*p + r*p;
    return dp[r][s][p]  = fr(r,s-1,p) * (r*s/total) + fr(r,s,p-1) * (s*p/total) + fr(r-1,s,p) * (r*p/total);
}

long double fs(int r, int s, int p){
    //base case
    if(p==0) return 0.0;
    if(s==0) return 0.0;
    if(r==0) return 1.0;
    
    if(dp[r][s][p] > -0.9) return dp[r][s][p];
    long double total = r*s + s*p + r*p;
    return dp[r][s][p]  = fs(r,s-1,p) * (r*s/total) + fs(r,s,p-1) * (s*p/total) + fs(r-1,s,p) * (r*p/total);
}

long double fp(int r, int s, int p){
    //base case
    if(p==0) return 0.0;
    if(r==0) return 0.0;
    if(s==0) return 1.0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];
    long double total = r*s + s*p + r*p;
    return dp[r][s][p]  = fp(r,s-1,p) * (r*s/total) + fp(r,s,p-1) * (s*p/total) + fp(r-1,s,p) * (r*p/total);
}


void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    int r,s,p;
    cin>>r>>s>>p;
    memset(dp,-1.0,sizeof dp);
    long double resr = fr(r,s,p);
    memset(dp,-1.0,sizeof dp);
    long double ress = fs(r,s,p);
    memset(dp,-1.0,sizeof dp);
    long double resp = fp(r,s,p);
    cout<<fixed<<setprecision(12)<<resr<<" "<<ress<<" "<<resp;
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