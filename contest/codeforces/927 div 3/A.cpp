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
    string input;
    cin>>input;
    int ans = 0;
    int brak = 0;
    bool check = false;
    for(int i = 0; i<n-1; i++){
        if(input[i] == '*' and input[i+1] == '*'){
            brak = i;
            check = true;
            break;
        }
    }
    debug(brak);
    if(check == false){
        for(int i = 0; i<n; i++){
        if(input[i] == '@') ans++;
        }
    }
    else{
        for(int i = 0; i<brak;i++){
            if(input[i] == '@') ans++;
        }
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