#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<unordered_map>
#include<unordered_set>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#else
#define debug(x)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;
int dp[22][1<<22];
int f(int i, int mask , int n, vector<vector<int> > & c){
    // base case 
    if(i==n+1 ){
        if(mask == 0) return 1;
        return 0;
    }
    if(dp[i][mask] != -1) return dp[i][mask];
    int ans  = 0;
    for(int w = 1;w<=n;w++){
        if(c[i][w] ==1 and ((mask & (1<<(w-1))) != 0)){ // compatible and available
            ans = ((ans%mod) + (f(i+1,(mask ^ (1<<(w-1))), n, c))%mod)%mod;
        }
    }
    return dp[i][mask] = ans;
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int> > c(n+1,vector<int> (n+1));
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n;j++){
            cin>>c[i][j];
        }
    }
    memset(dp,-1,sizeof dp);
    cout<<f(1,(1<<n)-1,n,c);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}