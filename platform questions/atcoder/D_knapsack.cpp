#include<iostream>
#include<vector>

#include<climits>
#include<algorithm>
#define ll long long int
using namespace std;
vector<vector<ll> > dp(105, vector<ll>(100005, -1));
ll f(vector<int> &wts, vector<int> &val, int idx, int w){
    // base case
    if(idx == wts.size()) return 0;
    if(dp[idx][w] != -1) return dp[idx][w];
    ll ans = INT_MIN;
    ans = max(ans, f(wts,val,idx+1,w));
    if(wts[idx] <= w){
        ans = max(ans, val[idx] + f(wts,val,idx+1 , w-wts[idx]));
    }
    return dp[idx][w] = ans;
}
vector<vector<ll> > dp2(105, vector<ll>(100005, 0));
ll fbu(vector<int> &wts,vector<int> &val, int w){
    int n = wts.size();
    for(int idx = n-1; idx>=0; idx--){
        for(int j = 0; j<= w ; j++){
            ll ans = INT_MIN;
            ans = max(ans,dp2[idx+1][j]);
            if(wts[idx]<=j){
                ans = max(ans, val[idx] + dp2[idx+1][j-wts[idx]]);
            }
            dp2[idx][j] = ans;
        }
    }
    return dp2[0][w];

}

int main(){
    int n;
    cin>>n;
    int w;
    cin>>w;
    vector<int> wt;
    vector<int> val;
    for(int i=0;i<n;i++){
        int w,v;
        cin>>w>>v;
        wt.push_back(w);
        val.push_back(v);
    }
    cout<<fbu(wt,val,w);
    return 0;
}