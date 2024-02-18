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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    string str;
    cin>>str;
    vector<int> ans;
    int i = 0;
    int j = n-1;
    int product = 1;
    for(int i = 0; i<n; i++){
        product = ((product % m) * (input[i]%m))%m;
    }
    ans.push_back(product);
    int count = 1;
    while(count!=n){
        
    }
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
    while(t--){
        solve();
    }
return 0;
}