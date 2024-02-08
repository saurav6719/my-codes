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
    if(n>=1 and n<=9){
        cout<<n<<endl;
        return;
    }
    vector<int> v(18,0);
    int i = 1;
    int c = 9;
    while(i<=17){
        v[i] = c*i;
        c*=10;
        i++;
    }
    for(int i = 2; i<=18;i++){
        v[i] += v[i-1];
    }
    int great = -1;
    for(int i = 1; i<=18; i++){
        if(v[i] < n) great = i+1;
        else break;
    }
    // great digit number
    //cout<<great;
    int start = v[great - 1] + 1;
    //cout<<start;
    int remai = n - start + 1;
    int quo = remai / great;
    int rema = remai % great;
    int startOfGreat = pow(10,great-1);
    debug(startOfGreat);
    startOfGreat += quo-1;
    debug(startOfGreat);
    string s = to_string(startOfGreat);
    if(rema == 0 ){
        cout<<s[s.size() - 1]<<endl;
        return;
    }
    startOfGreat ++;
    string s2 = to_string(startOfGreat);
    cout<<s2[rema-1]<<endl;

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