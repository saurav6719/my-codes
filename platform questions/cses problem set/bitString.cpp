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
int power(int a, int x, int p = mod){
    //finding a to the power x
    int res = 1;
    a = a % p;
    while(x>0){
        if(x & 1){
            res = (res * a) % p;
        }
        x = x >> 1;
        a = (a * a) % p;
    }
    return res;

}

int modInverse(int n){
    // mod inverse of n wrt 1e9+7
    return power(n,mod-2);
}

int nCr(int n, int r, int p = mod){
    if(n<r) return 0;
    if(r==1) return 1;
    vector<int> factorial(n+1,0);
    factorial[0] = 1;
    for(int i = 1; i<= n ;i++){
        factorial[i] = (factorial[i-1] * i) % p;
    }
    return (factorial[n] * modInverse(factorial[r]) % p  * modInverse(factorial[n-r]) % p);
}

void solve(){
    int n;
    cin>>n;
    cout<<power(2,n);

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