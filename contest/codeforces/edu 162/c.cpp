#include<bits/stdc++.h>
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
    int n,q;
    cin>>n>>q;
    vector<int> input(n+1);
    for(int i = 1; i<=n; i++){
        cin>>input[i];
    }
    vector<int> oc(n+1,0);
    vector<int> sumc(n+1,0);
    for(int i = 1; i<=n; i++){
        if(input[i] == 1) {
            oc[i] = oc[i-1]+1;
            sumc[i] = sumc[i-1];
        }
        else{
            oc[i] = oc[i-1];
            sumc[i] = sumc[i-1]+input[i]-1;
        }
    }
    // for(int i = 0; i<=n; i++){
    //     cout<<oc[i]<<" ";
    // }
    // cout<<endl;
    // for(int i = 0; i<=n; i++){
    //     cout<<sumc[i]<<" ";
    // }
    cout<<endl;
    while(q--){
        int l,r;
        cin>>l>>r;
        if(l==r){
            cout<<"NO"<<endl;
            continue;
        }
        int x = sumc[r]- sumc[l-1];
        debug(sumc[r]);
        debug(sumc[l]);
        debug(oc[r]);
        debug(oc[l]);
        debug(x);
        int y = oc[r] - oc[l-1];
        debug(y);
        if(x<y) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }


}
signed main(){
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