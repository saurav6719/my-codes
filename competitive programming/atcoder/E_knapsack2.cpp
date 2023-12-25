#include<iostream>
#include<vector>

#include<climits>
#include<algorithm>
#define ll long long int
using namespace std;

vector<vector<ll> > dp(105, vector<ll>(100005, -1));

ll f(vector<int> &wts, vector<int> &val, int idx, int target){
    // base case
    if(target == 0) return 0; 
    if(idx == wts.size()) return INT_MAX;
    if(dp[idx][target] != -1) return dp[idx][target];
    ll ans = INT_MAX;
    ans = min(ans, f(wts,val,idx+1,target));  // not pick
    if(val[idx] <= target){
        ans = min(ans, wts[idx] + f(wts,val,idx+1 , target-val[idx]));
    }
    return dp[idx][target] = ans;
}
vector<vector<ll> > dp2(105, vector<ll>(100005, INT_MAX));
ll fbu(vector<int> &wts,vector<int> &val, int target, int capacity){
    int n = wts.size();
    for(int i = 0; i<105;i++){  
        dp2[i][0] = 0;   // if target == 0 return 0
    }
    for(int idx = n-1; idx>=0; idx--){
        for(int j = 0; j<= target ; j++){
            ll ans = INT_MAX;
            ans = min(ans,dp2[idx+1][j]);
            if(val[idx]<=j){
                ans = min(ans, wts[idx] + dp2[idx+1][j-val[idx]]);
            }
            dp2[idx][j] = ans;
        }
    }
    int result = -1;
    for(int i = 0; i<=n*1000; i++){
        if(dp2[0][i] <= capacity){
            result = i;
        }
    }
    return result;

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

    cout<<fbu(wt,val,n * 1000,w );
    return 0;
}