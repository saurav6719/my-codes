#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int ans = INT_MAX;
    int index1 = -1;
    int index2 = -1;
    for(int i = 0; i<n-1; i++){
        int res = min(ans , abs(arr[i]- arr[i+1]));
        if(res < ans) {
            ans = res;
            index1 = i;
            index2 = i+1;
        }

    }

    int ans2 = abs(arr[0] - arr[n-1]);
    if(ans2 < ans) {
        index1 = 0;
        index2 = n-1;
    }
    cout<<index1+1<<" "<<index2+1;
}
int32_t main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}