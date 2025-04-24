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
int n;
vector<int> dp(1e7);
void f(){
    dp[1] = 1;
    for(int i=2;i<=2*1e5;i++){ 
        int j=i; 
        int curr=0; 
        while(j>0){ 
            curr+=j%10; 
            j/=10; 
        } 
        dp[i]=dp[i-1]+curr; 
    }
}

void solve(){
    
    
    cin>>n;
    cout<<dp[n]<<endl;

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin>>t;
    //t = 1;
    f();
    while(t--){
        solve();
    }
return 0;
}