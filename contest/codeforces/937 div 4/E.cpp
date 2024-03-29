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
 
vector<int> findDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            // If i is a divisor, add it to the list
            divisors.push_back(i);
            
            // If i is not the square root of n, then n/i is also a divisor
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}
 
bool poss(int i, string &str) {
  
    string ff = str.substr(0, i);
    string ss = str.substr(i, i);
    while (ff.length() < str.length()) {
        ff += ff;
    }
    while (ss.length() < str.length()) {
        ss += ss;
    }
    int cntf = 0;
    int cnts = 0;
    for (int i = 0; i < str.size(); i++) {
        if (ff[i] != str[i]) cntf++;
        if (ss[i] != str[i]) cnts++;
    }
    if (cntf <= 1 || cnts <= 1) return true;
    return false;
}
void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
 
    vector<int> div = findDivisors(n);
    int ans = n;
    for(int i = 0; i<div.size(); i++){
      if(div[i] == n) {
        ans = min(ans , div[i]);
        continue;
      }
      if(poss(div[i],str)){
        debug(div[i]);
        ans = min(ans,div[i]);
      }
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}
 