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
void solve () {
    int n;
    cin >> n;
    vector<int> V(n);
    for (int i = 0; i < n; i++) {
        cin >> V[i];
    }
    int a = numeric_limits<int>::max();
    int b = numeric_limits<int>::max();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (a > b) {
            swap(a, b);
        }
        if (V[i] <= a) {
            a = V[i];
        } 
        else if (V[i] <= b) {
            b = V[i];
        } 
        else {
            a = V[i];
            cnt++;
        }
    }

    cout << cnt << "\n";

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