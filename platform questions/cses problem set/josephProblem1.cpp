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
    int n;
    cin>>n;
    vector<int> now(n);
    for(int i = 0; i<n; i++){
        now[i] = i+1;
    }
    while(now.size() > 1){
        vector<int> survivor;
        for(int i = 0; i<now.size(); i++){
            if(i%2 == 1){
                cout<<now[i]<<" ";
            }
            else survivor.push_back(now[i]);
        }
        if(now.size()%2 == 0){
            now = survivor;
        }
        else{
            int x = survivor.back();
            survivor.pop_back();
            now.clear();
            now.push_back(x);
            for(int i = 0; i<survivor.size(); i++){
                now.push_back(survivor[i]);
            }
        }
    }
    cout<<now[0];

}
signed main(){
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