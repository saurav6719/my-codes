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
    int a,b;
    cin>>a>>b;
    if(a%2 != 0 and b%2 != 0 ){
        cout<<"No"<<endl;
        return;
    }
    if(a%2 == 0 and b%2 != 0){
        if(b*2 == a){
            cout<<"No"<<endl;
            return;
        }
        else {
            cout<<"Yes"<<endl;
            return;
        }
    }
    if(a%2 == 0 and b%2 == 0){
        cout<<"Yes"<<endl;
        return;
    }
    if(a%2 != 0 and b%2 == 0){
        if(a*2 == b){
            cout<<"No"<<endl;
            return;
        }
        else {
            cout<<"Yes"<<endl;
            return;
        }
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