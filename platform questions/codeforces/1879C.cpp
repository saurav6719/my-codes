/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Saurav     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \___/   /
           \  -----  /
             \_____/
  
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
#define MOD 998244353
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */

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
    string str;
    cin>>str;
    int n = str.size();
    int op = 0;
    int total = 0;
    int i = 1;
    vector<int> num;
    while(i<n){
        int cnt = 1;
        while(str[i] == str[i-1]){
            cnt++;
            i++;
        }
        if(cnt>1) num.push_back(cnt);
        op += cnt - 1;
        total += cnt;
        i++;
    }
    print(num);
    int m = num.size();
    
    int ans = 1;
    for(int i = 0; i<m; i++){
        debug(nCr(num[i], num[i] - 1));
        ans = (ans % MOD * nCr(num[i], num[i] - 1) % MOD) % MOD;
    }
    debug(ans);
    
    ans = (ans % MOD * factorial(op) % MOD) % MOD;
    if(op == 0) ans = 1;
    cout<<op<<" "<<ans<<endl;
    
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

