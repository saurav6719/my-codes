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
void solve(){
    int n;
    int d;
    cin>>n>>d;
    vector<int> input(n);
    
    for(int i = 0 ;i<n; i++){
        cin>>input[i];
    }
    sort(input.begin(), input.end(),greater<int> ());
    int i = 0;
    int j = n-1;
    int ans = 0;

    while(i<=j){
        int number = d / input[i];
        number ++;
        if(j-i+1 >= number) ans++;
        i++;
        j-=(number-1);
    }
    
    cout<<ans<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}