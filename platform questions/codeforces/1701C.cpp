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

bool poss(int mid, unordered_map<int,int> &freq){
    int left = 0;
    int help = 0;
    for(auto ele: freq){
        if(mid == ele.second) continue;
        if(mid<ele.second) left += ele.second - mid;
        else help += (mid-ele.second) / 2;
    }
    if(left<=help) return true;
    return false;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> input(m);
    unordered_map<int,int> freq;
    for(int i = 0; i<m; i++){
        int ele;
        cin>>ele;
        input[i] = ele;
        freq[ele]++;
    }
    for(int i = 1; i<=n; i++){
        if(freq.count(i) == 0){
            freq[i] = 0;
        }
    }
    int lo = 1;
    int hi = 2*m;
    int ans = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        //debug(mid);
        if (poss(mid,freq)){
            ans = mid;
            hi = mid - 1;
            //debug(hi);
        }
        else {
            lo = mid + 1;
            //debug(lo);
        }
    }
    cout<<ans<<endl;
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