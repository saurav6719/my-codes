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
    vector<int> prices(n);
    for(int i = 0; i<n; i++){
        cin>>prices[i];
    }
    sort(prices.begin(), prices.end());
    int mid ;
    if(n&1) mid = n/2;
    else mid = (n/2) - 1;
    int i = mid-1;
    debug(i);
    int j = mid+1;
    debug(j);

    vector<int> ans;
    ans.push_back(prices[mid]);
    while(i>=0 or j < n){
        if(i>=0)ans.push_back(prices[i]);
        if(j<n)ans.push_back(prices[j]);
        i--;
        j++;
    }

    cout<<mid<<endl;
    for(int i = 0; i<n; i++){
        cout<<ans[i]<<" ";
    }


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