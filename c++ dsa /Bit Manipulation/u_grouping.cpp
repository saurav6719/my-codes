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

vector<int> dp((1<<16), INT_MAX); // initialising with int max because in some case
                                // can be -1 
vector<int> cost((1<<16),0);

int calculate(vector<vector<int> > &grid, int mask){
    int ans = 0;
    for(int i = 0;i<=16; i++){
        for(int j = i+1; j<=16;j++){
            if(((mask & (1<<i))!= 0) and ((mask & (1<<j))!= 0)){ // ith and jth bit is set 
                ans += grid[i][j];
            }
        }
    }
    return ans;
}

void precost(vector<vector<int> > &grid, int n){
    for(int mask = 1; mask<=((1<<n) -1); mask ++){
        cost[mask] = calculate(grid,mask);
    }
}

int f(vector<vector<int> >&grid, int mask ){
    if(mask == 0) return 0; //same compatiblity is zero 
    if(dp[mask] != INT_MAX) return dp[mask];
    int ans = 0;
    for(int g = mask ; g!=0; g= ((g-1) & mask)){
        ans = max(ans, cost[g] + f(grid, (mask ^ g)));

    }
    return dp[mask] = ans;

}
void solve(){
    int n;
    cin>>n;
    vector<vector<int> > input(n,vector<int>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0 ; j<n; j++){
            cin>>input[i][j];
        }
    }

    precost(input,n);
    cout<<f(input,((1<<n) - 1));
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