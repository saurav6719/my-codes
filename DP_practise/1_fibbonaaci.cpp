// #include<iostream>
// #include<vector>
// #include<string>
// #include<climits>
// #include<cmath>
// #include<algorithm>
// #include<unordered_map>
// #include<unordered_set>
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
// vector<int> dp;
// int fib(int n){
//     if(n==0 or n==1) return n;
//     if(dp[n] != -1) return dp[n];
//     return dp[n] = fib(n-1) + fib(n-2);
// }
// void solve(){
//     int n;
//     cin>>n;
//     dp.clear();
//     dp.resize(n+5,-1);
//     cout<<fib(n);
// }
// int32_t main(){
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
//     }
// return 0;
// }


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
vector<int> dp;
void solve(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+5,-1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2 ; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[n];
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