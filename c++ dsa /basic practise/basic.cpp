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
    string s;
    cin>>s;
    int n=s.length();
    int count=0;
    if(n<7) {
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<n-6;i++){
        if((s[i]==s[i+1]==s[i+2]==s[i+3]==s[i+4]==s[i+5]==s[i+6]=='0') or (s[i]==s[i+1]==s[i+2]==s[i+3]==s[i+4]==s[i+5]==s[i+6]=='1')){
           count=7;
           debug(count);
           break;
        }
    }
    
    if(count==7) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int32_t main(){
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