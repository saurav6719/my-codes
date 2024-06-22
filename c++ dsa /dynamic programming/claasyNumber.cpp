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
int dp[20][2][4];
int f(string &s , int idx, bool smaller , int cnt){
    if(cnt > 3) return 0;
    if(idx == s.size()) return 1;
    if(dp[idx][smaller][cnt] != -1) return dp[idx][smaller][cnt];
    int loop;
    if(smaller){
        loop = 9;
    }
    else loop = s[idx] - '0';
    int ans = 0;
    for(int i = 0; i<=loop ; i++){
        bool newsmaller;
        if(smaller) newsmaller = true;
        else {
            if(i < (s[idx] - '0')) newsmaller = true;
            else newsmaller = false;
        }
        ans += f(s, idx+1, newsmaller , cnt + ( (i!=0) ? 1 : 0));
    }
    return dp[idx][smaller][cnt] = ans;
}
void solve(){
    int l,r;
    cin>>l>>r;
    string strr = to_string(r);
    string strl = to_string(l-1);
    memset(dp, -1, sizeof dp);
    int rightans = f(strr , 0, 0, 0);
    memset(dp, -1, sizeof dp);
    int leftans = f(strl , 0, 0, 0);
    cout<<rightans - leftans<<endl;

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

