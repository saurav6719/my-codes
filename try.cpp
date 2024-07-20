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
// #define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define ll long long int
using namespace std;

/* write core logic here */

int binaryStringToInt(const string& binaryString) {
    int result = 0;
    int length = binaryString.length();
    
    for (int i = 0; i < length; ++i) {
        if (binaryString[length - 1 - i] == '1') {
            result += pow(2, i);
        }
    }
    
    return result;
}



string getbinary(int x){
    bitset<64> b(x);
    return b.to_string();
}
void solve() {
    ll n;
    cin >> n;
    ll n_copy = n;
    string str = getbinary(n);
        ll bitCnt = 0;
    while (n_copy > 0) {
        if (n_copy & 1) bitCnt++;
        n_copy >>= 1;
    }

    if(n==1){
      cout<<1<<endl;
      cout<<1<<endl;
      return;
    }

    vector<vector<ll>> ans;
    vector<ll> first;
    ll s;
    if (bitCnt % 2 == 1) {
        s = 0;
        for (ll i = 0; i < bitCnt; i++) {
            first.push_back(s);
            s = !s;
        }
    } else {
        s = 0;
        for (ll i = 0; i < bitCnt; i++) {
            first.push_back(s);
            s = !s;
        }
    }
    ans.push_back(first);
    ll pos = 1;
    while (true) {
        vector<ll> v = ans[pos - 1];
        v.insert(v.begin(), 1);
        while (v.size() > bitCnt) {
            v.pop_back();
        }
        ans.push_back(v);
        ll cnt = 0;
        for(ll i=0; i<v.size(); i++){
            if(v[i] == 1) cnt++;
        }
        if(cnt == bitCnt) break;
        pos++;
    }

    // for(auto &it : ans){
    //     print(it);
    // }

    cout << ans.size() << endl;

    for(ll i=0; i<ans.size(); i++){
        ll curr = 0;
        ll num = n;
        for(ll j = 0; j < 63; j++){
            if((1 & (num >> j)) == 1){
                num = (num & ans[i][curr]);
                curr++; 
            }
        }
    }


    vector<int> final;

    // print(str);

    for(int i = 0; i<ans.size(); i++){
      int curr = 0;
      string s;
      s.resize(64, '0');

      for(int j = 0 ;j<64; j++){
        if(str[j] == '1'){
          s[j] = ans[i][curr] + '0';
          curr++;
        }
      }

      // print(s);

      final.push_back(binaryStringToInt(s));

    }

    for(auto ele : final){
      cout<<ele<<" ";


    }

    cout<<endl;





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

