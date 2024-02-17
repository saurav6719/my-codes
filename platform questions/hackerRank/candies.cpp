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
//link -> https://www.hackerrank.com/challenges/candies/problem
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    vector<int> ans1(n,1);
    for(int i = 1; i<n; i++){
        if(input[i] > input[i-1]) ans1[i] = ans1[i-1] + 1;
    }

    vector<int> ans2(n,1);
    for(int i = n-2; i>=0; i--){
        if(input[i] > input[i+1]) ans2[i] = ans2[i+1] + 1;
    }

    vector<int> ans(n);
    int sum = 0;
    for(int i = 0; i<n; i++){
        ans[i] = max(ans1[i], ans2[i]);
        sum += ans[i];
    }
    cout<<sum;

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