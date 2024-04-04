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
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */

int highestPowerof2(int n) {
    // If n is a power of 2, return n
    if (n && !(n & (n - 1)))
        return n;

    // Set the leftmost bit of n to 0
    while (n & (n - 1)) {
        n = n & (n - 1);
    }

    return n;
}

int idx(int n){
    int cnt = 0;
    while(n!=0){
        cnt++;
        n/=2;
    }
    return cnt-1;
}

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


int f(int n, int k, int cnt){
    //base case 
    //debug(n);
    if(n==1) return 2;
    if(n==0) return 1;
    int near = highestPowerof2(n);

    int pow = idx(near);
    //debug(pow);

    if(k<=pow){
        return power(2,k);
    }

    int sum = 0;
    sum = power(2,pow) + f(n-near, k, cnt);
    cnt += sum;
    return cnt;
}
void solve(){
    int n,k;
    cin>>n>>k;
    cout<<f(n,k, 0)<<endl;

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

