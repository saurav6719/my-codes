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
int m,n;
vector<int> t(n);
vector<int> z(n);
vector<int> y(n);
vector<int> ans(n);
bool poss(int mid){
    int res = 0;
    for(int i = 0; i<n; i++){
        int ballon = mid / ((t[i] * z[i]) + y[i]);
        int rem = mid - ballon * (((t[i] * z[i]) + y[i]));
        ballon *= z[i];
        if(rem >= t[i]){
            if(rem/t[i] > z[i]){
                ballon += z[i];
            }
            else{
                ballon += rem/t[i];
            }

        }
        ans[i] = ballon;
        res += ans[i];
    }
    return res >= m;
    
}

void solve(){
    
    cin>>m>>n;
    for(int i = 0; i<n; i++){
        cin>>t[i];
        cin>>z[i];
        cin>>y[i];
    }
    int lo = 0;
    int hi = 1e9;
    int res = -1 ;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if (poss(mid)){
            res = mid;
            hi = mid -1;
        }
        else lo = mid +1;
    }
    //cout<<res<<endl;
    
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