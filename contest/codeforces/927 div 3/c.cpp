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
vector<int> ans;
int f(vector<int> &input, string &s, int l, int r, int i, int m){
    //base case
    if(l==r) return ans[i] = input[l] % m;
    if(s[i] == 'L') return ans[i] = (f(input,s,l+1,r,i+1,m) * input[l]) % m;
    else return ans[i] = (f(input,s,l,r-1,i+1,m) * input[r])%m ;
}
void solve(){
    int n,m;
    cin>>n>>m;
    ans.resize(n);
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    string str;
    cin>>str;
    f(input,str,0,n-1,0,m);
    //reverse(ans.begin(), ans.end());
    for(int i = 0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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