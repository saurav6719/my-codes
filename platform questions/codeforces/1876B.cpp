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
#define mod 998244353
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
const int MOD = 998244353;

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

std::vector<int> find_factors(int n) {
    std::vector<int> factors;

    // Loop from 1 to sqrt(n)
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);  // i is a factor
            if (i != n / i) {
                factors.push_back(n / i);  // n / i is also a factor
            }
        }
    }

    return factors;
}

int f(int rem, int time){
  debug(rem);
  int res = 0;
  for(int i = 0; i<time; i++){
    res += rem;
    res %= mod;
    rem *= 2;
    rem %= mod;
  }
  debug(res);
  return res;
}

bool cmp(pair<int,int> &a, pair<int,int> &b){
  return a.first > b.first;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int, int> >input(n);
    for(int i = 0; i<n; i++){
      cin>>input[i].first;
      input[i].second = i+1;
    }

    vector<vector<int> > factors(n+5 , vector<int> ());


    for(int i = 1; i<=n; i++){
      vector<int> v = find_factors(i);
      factors[i] = v;
    }

    sort(input.begin(), input.end(), cmp);

    int ans = 0;
    int ts = n;
    
    vector<int> visited(n+5, -1);
    for(int i =  0; i<n; i++){
      int idx = input[i].second;
      int sz = 0;
      for(auto ele : factors[idx]){
        if(visited[ele] == -1){
          visited[ele] = 1;
          sz++;
        }

      }
      ans += (f(power(2,ts - sz) , sz) * input[i].first);
      debug(sz);
      debug(ans);
      ans %= mod;
      ts = ts - sz;
    }
    cout<<ans<<endl;

}
/* logic ends */

signed main(){
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

