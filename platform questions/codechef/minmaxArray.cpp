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
bool ifPossible(vector<int> v, int mid){
    for(int i = v.size() - 1; i>0; i--){
        if(v[i] > mid){
            v[i-1]+= v[i] - mid;
            v[i] = mid;
        }
    }
    for(int i = 0; i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return *max_element(v.begin(), v.end()) <= mid;
}
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    int lo = 0;
    int hi = *max_element(input.begin(), input.end());
    debug(hi);
    int result = hi;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        debug(mid);
        if(ifPossible(input,mid)) {
            result = mid;
            hi = mid-1;
            debug(hi);
        }
        else {
            lo = mid+1;
            debug(lo);
        }
    }

    cout<< result<<endl;
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