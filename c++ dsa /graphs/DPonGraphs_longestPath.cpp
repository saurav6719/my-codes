#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<iomanip>
#include <cstring>
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
vector<int> graph[100005];
int dp[100005];
int f(int src){
    if(dp[src] != -1) return dp[src];
    int maxi = 0;
    bool leaf = 1;
    for(int child : graph[src]){
        leaf = 0;
        maxi = max(maxi, f(child));
    }
    return dp[src] = leaf ? 0 : 1 + maxi;
}
void solve(){
    memset(dp,-1,sizeof(dp));
    int n,m;
    cin>>n>>m;
    for(int i = 0; i<m; i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    int result = INT_MIN;
    for(int i = 1; i<=n; i++){
        result = max(result , f(i));
    }
    cout<<result;
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