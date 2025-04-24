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
    vector<int> start(n);
    vector<int> end(n);
    for(int i = 0; i<n; i++){
        cin>>start[i];
        cin>>end[i];
    }
    sort(start.begin(),start.end());
    sort(end.begin(), end.end());
    int i = 0;
    int j = 0;
    int ans= INT_MIN;
    int curr = 0;
    while(i<n and j<n){
        while(start[i] <= end[j] and i<n){
            i++;
            curr++;
            debug(curr);
            debug(i);
            ans = max(ans,curr);
        }
        if(i>=n) break;
        while(end[j] < start[i] and j<n) {
            
            j++;
            curr--;
            ans = max(ans,curr);
            debug(curr);
        }
    }
    cout<<ans;


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