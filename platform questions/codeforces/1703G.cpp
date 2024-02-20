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
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    int ans = INT_MIN;
    int sum = 0;
    for(int i = -1; i<n-1;i++){
        
        int now = sum;
        debug(now);
        for(int j = i+1; j< min(n,i+32ll); j++){
            int curr = input[j];
            curr = curr>>(j-i);
            debug(j-i);
            debug(curr);
            now += curr;
            ans = max(ans,now);
            debug(now);

        }
        sum += input[i+1] - k;
    }
    ans = max(ans,sum);
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