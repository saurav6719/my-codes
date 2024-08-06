/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Shivam     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \_/   /
           \  -----  /
             \_/
  
  Happy coding! 
*/

/* includes and all */

#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */

const int MOD = 1e9 + 7;

// Function to calculate power in modular arithmetic
long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1; // y = y/2
        x = (x * x) % MOD;
    }
    return res;
}

// Function to calculate factorial in modular arithmetic
long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; ++i)
        res = (res * i) % MOD;
    return res;
}

// Function to calculate nCr in modular arithmetic
long long nCr(int n, int r) {
    if (r == 0 || r == n)
        return 1;
    long long numerator = factorial(n);
    long long denominator = (factorial(r) * factorial(n - r)) % MOD;
    return (numerator * power(denominator, MOD - 2)) % MOD;
}


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    bool pos = true;
    bool neg = true;
    
    for(int i=0;i<n;i++){
        if(arr[i]<=0){
            pos=false;
        }
        else{
            neg = false;
        }
    }
    if(neg==true){
       int ans1=0;
        for(int i=0;i<n;i++){
            ans1+=arr[i];
            ans1 %= mod;
        }
        debug(ans1);
        int rans1 = ((ans1 + mod) % mod ) % mod; 
        
        if(rans1 < 0){
            rans1 = (rans1 + mod) % mod;
        }// Adjusting for negative values
        cout << rans1 << endl;
        return;
    }
    int posans=0;
    if(pos==true){
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
            sum %= mod;
        }
        int factor = power(2, k) - 1;
        int ans = (factor % mod * sum % mod ) % mod;
        ans += sum;
        ans %= mod;

        if(ans < 0){
            ans = (ans + mod) % mod;
        }

        cout<<ans<<endl;
        return;
    }
    int curr=0;
    int sum=INT_MIN;
    for(int i=0;i<n;i++){
        curr+=arr[i];
        if(curr>sum){
            sum=curr;
        }
        if(curr<0){        // kadanes algo for max sum subarray
            curr=0;
        }
    }
    debug(sum);
    int ksum=0;
    for(int i=0;i<n;i++){
        ksum+=arr[i];
    }
    if(pos==false and neg==false){
        int factor = power(2, k) - 1;
        // first time sum then 2sum then 4sum then 8sum .... 
        // total 2 ki power k - 1 times sum add hoga 
        int add = ((factor % mod) * (sum % mod)) % mod;
        debug(add);
        debug(ksum);
        add += ksum;
        add %= mod;
        if(add < 0){
            add = (add + mod) % mod;
        }
        cout<<add<<endl;
        return ;
    }
}
/* logic ends */

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

