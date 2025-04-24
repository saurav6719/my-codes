// #include<bits/stdc++.h>
// #ifndef ONLINE_JUDGE
// #define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
// #else
// #define debug(x)
// #endif
// #define endl "\n"
// #define int long long int
// #define mod 1000000007
// #define mn(a,b,c) min(a,min(b,c))
// #define mx(a,b,c) max(a,max(b,c))
// using namespace std;
// //link -> https://atcoder.jp/contests/dp/tasks/dp_b
// vector<int> dp;
// int f(vector<int> &heights, int i, int k){
//     if(i>=heights.size()) return INT_MAX;
//     if(i == heights.size()- 1) return 0;
//     if(dp[i] != -1) return dp[i];
//     int ans = INT_MAX;
//     for(int j = 1; j<=k; j++){
//         if(i+j >= heights.size()) break;
//         ans = min(ans, abs(heights[i] - heights[i+j]) + f(heights,i+j,k));
//     }
//     return dp[i] = ans;
// }
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     vector<int> heights(n);
//     for(int i = 0; i<n; i++){
//         cin>>heights[i];
//     }
//     int ans = INT_MAX;
//     dp.clear();
//     dp.resize(n+5,-1);
    
//     cout<<f(heights,0,k);

// }
// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     #ifndef ONLINE_JUDGE
//         freopen("Error.txt" , "w" , stderr);
//     #endif
//     int t;
//     //cin>>t;
//     t = 1;
//     while(t--){
//         solve();
//     // }
// return 0;
// }


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
//link -> https://atcoder.jp/contests/dp/tasks/dp_b
vector<int> dp;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> heights(n);
    for(int i = 0; i<n; i++){
        cin>>heights[i];
    }
    int ans = INT_MAX;
    dp.clear();
    dp.resize(n+5,INT_MAX);
    dp[n-1] = 0;
    for(int i = n-2; i>=0; i--){
        for(int j = 1; j<=k; j++){
            if(i+j >= n) break;
            dp[i] = min(dp[i], (abs(heights[i] - heights[i+j]) + dp[i+j]));
        }
    }

    cout<<dp[0];

}
signed main(){
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