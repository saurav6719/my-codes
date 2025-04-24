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
int n;
string str;
int f(int i , int c, string & ans){
    //base case
    if(i==n-1){
        // debug(i);
        // debug(c);
    
        c+= str[i] - '0';
        ans+=(c%10 + '0');
        return c/10;
    }
    // debug(i);
    
    int ch = str[i] - '0';
    // debug(ch);
    c+= ch;
    //debug(c);
    c+= f(i+1,c,ans);
    
    if(i==0){
        while(c>0){
            ans+= (c%10 + '0');
            c/=10;
        }
    }
    else ans+=(c%10 + '0');
    return c/10;
}
void solve(){
    cin>>n;
    cin>>str;
    string ans = "";
    f(0,0,ans);
    reverse(ans.begin(), ans.end());
    int start = 0;
    for(int i = 0; i<ans.size(); i++){
        if(ans[i] != '0') {
            start = i;
            break;
        }
    }
    for(int i = start; i<ans.size(); i++){
        cout<<ans[i];
    }
    cout<<endl;
    
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