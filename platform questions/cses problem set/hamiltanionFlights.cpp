#include<bits/stdc++.h>
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
int dp[20][1<<20];

int f(int i, int mask, vector<vector<int> > &graph){
    if(i == 0){
        if(mask == 1) return 1;
        return 0;
    }
    if((mask & (1<<i)) == 0){
        return 0;
    }
    if(dp[i][mask] != -1) return dp[i][mask];

    int ans = 0;
    int newmask = (mask ^ (1<<i));
    for(auto ele : graph[i]){
        ans += f(ele, newmask, graph);
        ans %= mod;
    }
    return dp[i][mask] = ans;
}
void solve(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int> > graph(n+5, vector<int> ());
    for(int i = 1; i<=m; i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        graph[v].push_back(u);
    }

    memset(dp, -1, sizeof dp);
    
    cout<<f(n-1, (1<<n)-1, graph);



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