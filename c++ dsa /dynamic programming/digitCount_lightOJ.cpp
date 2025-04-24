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
set<int> st;
int dp[20][15][15];
int f(string &s , int idx, int last , int slast){
    if(idx > 1 and (abs (last - slast) > 2)) return 0;
    if((idx == s.size())) {
        //print(curr);
        return 1;
    }
    if(dp[idx][last][slast] != -1 ) return dp[idx][last][slast];
    //if(dp[idx] != -1) return dp[idx];
    int ans = 0;
    for(int i = 1; i<=9 ; i++){
        if(st.count(i) == 0) continue;
        ans += f(s, idx+1 , i, last);
    }
    return dp[idx][last][slast] = ans;
}
void solve(){
    int m;
    cin>>m;
    int n;
    cin>>n;
    st.clear();
    vector<int> v;
    for(int i = 0; i<m; i++){
        int a;
        cin>>a;
        st.insert(a);
        v.push_back(a);
    }
    string str = "";
    for(int i = 0; i<n; i++){
        str += '9';
    }

    memset(dp, -1, sizeof dp);
    int ans = 0;

    if(n==1){
        cout<<v.size()<<endl;
        return;
    }

    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++){
            ans += f(str, 2, v[i], v[j]);
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
    for(int i = 1; i<=t; i++){
        cout<<"Case "<<i<<": ";
        solve();
    }
return 0;
}

