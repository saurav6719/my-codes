#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
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
int dp[10][1<<10];
int tsp(vector<vector<int> > &grid, int curr, int mask , int n){
    // base case 
    if(mask == (1<<n) -1){
        return grid[curr][0];
    }
    if(dp[curr][mask] != -1) return dp[curr][mask];

    int ans = INT_MAX;
    for(int neigh = 0; neigh <n; neigh++){
        if((mask & (1<<neigh)) == 0){ // not visited
            ans = min(ans , grid[curr][neigh] + tsp(grid, neigh, mask | (1<<neigh),n ));
        } 
    }
    return dp[curr][mask] = ans;
}
void solve(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    vector<vector<int> > grid(n,vector<int> (n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    cout<<tsp(grid,0,1,n); // intially mask is 1 (0001); i.e 0 is visited 
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