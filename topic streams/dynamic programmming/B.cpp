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

//link -> https://codeforces.com/gym/302977/problem/B


void solve(){
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    set<char> st;
    for(int i =0 ;i<k; i++){
        char ch ;
        cin>>ch;
        st.insert(ch);
    }

    vector<int> dp(n+5);

    if(st.count(str[n-1])){
        dp[n-1] = 1;
    }
    else dp[n-1] = 0;

    for(int i = n-2; i>=0;i--){
        if(st.count(str[i]) == 0){
            dp[i] = 0;
            continue;
        }
        dp[i] = 1+dp[i+1];
    }
    int ans = 0;

    for(int i = 0; i<n; i++){
        ans += dp[i];
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

