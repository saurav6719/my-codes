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
    int k;
    int x;
    cin>>n>>k>>x;
    vector<int> input(n);
    for(int i = 0; i<n; i++) cin>>input[i];
    sort(input.begin(), input.end(), greater<int> ());
    vector<int> prefix(n+1,0);
    for(int i = 1; i<=n; i++){
        prefix[i] = prefix[i-1] + input[i-1];
    }
    int ans = INT_MIN;
    int sum  =0;
    for(int i = 0; i<n; i++){
        sum += input[i];
    }
    for(int i = 0; i<=k ; i++){
        int n_copy = n;
        n_copy -= i;
        int sum_copy = sum;
        sum_copy -= prefix[i];
        int remaining = min(n_copy , x);
        sum_copy -= 2 *  (prefix[i+remaining] - prefix[i]);
        ans = max(ans,sum_copy);
    }
    cout<<ans<<endl;


}
int32_t main(){
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}