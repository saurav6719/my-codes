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
int mxi(vector<int> input){
    int a = -1;
    int mn = INT_MIN;
    for(int i = 0; i<input.size() ;i++){
        if(input[i] > mn){
            a = i;
            mn = input[i];
        }
    }
    return a;
}-
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    int maxidx = mxi(input);
    int a = input[maxidx];
    debug(a);
    input[maxidx] = -1;
    for(int i = maxidx+1; i<n; i++){
        if(input[i] <= a){
            a=input[i];
            input[i] = -1;
        }
    }
    int b;

    bool flag = false;
    int ans = 0;


    for(int i = 0; i<n;i++){
        if(input[i] == -1) continue;
        if(!flag) {
            b = input[i];
            flag = true;
        }
        debug(b);
        debug(input[i]);
        if(input[i] > b){
            ans++;
        }
        debug(ans);
        b = input[i];
        debug(b);

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