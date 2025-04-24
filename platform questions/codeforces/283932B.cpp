#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<iomanip>
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
bool poss(vector<double> &a, double mid, int k){
    int count = 0;
    for(int i = 0; i<a.size(); i++){
        count += a[i]/ mid;
    }
    if(count >= k) return true;
    return false;
}
void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<double> a(n);
    double mna = INT_MIN;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        mna = max(mna, a[i]);
    }
    double lo = 0.0;
    double hi = 1e9+7;
    double result = mna;
    int count = 0;
    while(count < 50){
        double mid = lo + (hi-lo)/2;
        if(poss(a,mid,k)){
            result = mid;
            lo = mid;
        }
        else hi = mid;
        count++;
    }
    cout<<setprecision(20)<<result;
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