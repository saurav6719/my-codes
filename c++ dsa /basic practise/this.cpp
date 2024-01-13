#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#define endl "\n"
//#define int long long int
#define ll long long int
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,x;
    cin>>n>>k>>x;
    vector<int> input(n);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    sort(input.begin(), input.end());
    vector<ll> prefix(n+1,0);
    prefix[0] = input[0];
    for(int i = 1; i<n; i++){
        prefix[i] = prefix[i-1] + input[i];
    }

    vector<ll> suffix(n+1,0);
    suffix[n-1] = input[n-1];
    for(int i= n-2;i>=0;i--){
        suffix[i] = suffix[i+1] + input[i];
    }

    ll ans = LLONG_MIN;
    if(k>=n) {
        ans = 0;
    }
    int i = 0;
    while(i<=k){
        if(n-x-i < 0 ){
            ans = max(ans,(prefix[n-i-1] - 2*(suffix[0] - suffix[n-i])));
            break;
        }
        else{
            ans = max(ans,(prefix[n-i-1] - 2*(suffix[n-x-i] - suffix[n-i])));
        }
        i++;
    }
    cout<<ans<<endl; 
    }
    return 0;

}