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
#define ll long long int
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
bool isPossible(int k, string s){
    unordered_set<string> st;
    int len = s.length();

    int l = 0;
    int r = k;
  string str = s.substr(l, r-l+1);
    while(r < len){
        
        st.insert(str);
        l=r+1;
        r+=k;
    }

    if(st.size() == 1){
        return true;
    }
    if(st.size() > 2) return false;
    if(st.size() == 2){
      string res = "";
    int rep = len / str.size();
    while(rep--){
      res += str;
    }
    int cnt  =0;
    for(int i = 0; i<len; i++){
      if(res[i] != s[i]) cnt++;
    }

    if(cnt <= 1)return true;
    
    return false;
    }
}


void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<int>  divs = findDivisors(n);
    sort(divs.begin(), divs.end());
    int len = divs.size();
    int ans = s.length();

    for(int i=0; i<len; i++){
        if(isPossible(divs[i], s)){
            ans = divs[i];
            break;
        }
    }

    cout << ans << endl;
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

