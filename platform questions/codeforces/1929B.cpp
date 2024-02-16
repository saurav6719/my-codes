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
    int n;
    cin>>n;
    int d;
    cin>>d;
    int ans = 0;
    int count = 0;
    if(d<=n*2){
        if(d&1){
            cout<<(d/2)+1<<endl;
            return;
        }
        else {
            cout<<(d/2)<<endl;
            return;
        }
    }
    if(d==4*n+2){
        cout<<n<<endl;
        return;
    }
    else{
        ans+=n;
        d-=n*2;
        if(d<=(n-2)*2){
            if(d&1) ans+= (d/2)+1;
            else ans+= (d/2);
        }
        else {
            ans += (n-2);
            d -=(n-2)*2;
            ans+=d;
        }
        cout<<ans<<endl;
    }

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