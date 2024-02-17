#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<map>
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
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    int ans = 0;
    map<int,map<int,int> > mp;
    for(int i = 0; i<n; i++){
        // debug(input[i]);
        // debug((x-(input[i]%x))%x);
        // debug(input[i]%y);
        ans += mp[(x-(input[i]%x))%x][input[i]%y];
        //debug(ans);
        mp[(input[i]%x)%x][input[i]%y]++;
        //debug(mp.count([(x-(input[i]%x))%x][input[i]%y]));
    }
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