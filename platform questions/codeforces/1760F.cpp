#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
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

bool isPossible(int mid, vector<int> & sorted, int c, int d){
    int n = sorted.size();
    int sum = 0;
    for(int i = 0; i<d;i++){
        if(i%(mid+1) < n){
            sum += sorted[i%(mid+1)];
        }
    }
    return (sum >= c);
}
void solve(){
    int n,c,d;
    cin>>n>>c>>d;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    sort(input.begin(), input.end(), greater<int> ());

    int result = -1;
    int lo = 0;

    int hi = d+1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(isPossible(mid,input,c,d)){
            lo = mid+1;
            result = mid;
        }
        else {
            hi = mid-1;
        }
    }

    if(result >=d ) {
        cout<<"Infinity"<<endl;
        return;
    }

    if(result == -1){
        cout<<"Impossible"<<endl;
        return;
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