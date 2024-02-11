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
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    sort(input.begin(), input.end());
    unordered_set<int> visited;
    vector<int> unique;
    for(int i = 0; i<n; i++){
        if(visited.count(input[i])) continue;
        unique.push_back(input[i]);
        visited.insert(input[i]);
    }

    // for(int i = 0; i<unique.size(); i++){
    //     cout<<unique[i]<<" ";
    // }
    // cout<<endl;
    int result = INT_MIN;
    int ans = 0;

    for(int i = 0; i<n; i++){
        int l = unique[i];
        int r = unique[i] + n - 1;
        int a = lower_bound(unique.begin(), unique.end(), l) - unique.begin();
        int b = upper_bound(unique.begin(),unique.end(), r) - unique.begin();
        ans = b-a;
        result = max(result ,ans);
    }
    cout<<result<<endl;


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