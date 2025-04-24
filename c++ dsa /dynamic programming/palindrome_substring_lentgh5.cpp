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
bool notpalindrome (string a){
    string b = a;
    reverse(b.begin(), b.end());
    return b!=a;
}

int f(string previous, int index,string &s, vector<map<string,int> > &dp){
    // previous string is of 5 length 
    if(index == s.size()) return 1;  //true
    if(dp[index].find(previous) != dp[index].end()) return  dp[index][previous];
    string x1 =  previous.substr(1,4); // because one char we are adding so only 4 char 
    string x2 =  previous.substr(1,4);
    x1+='0';
    x2+='1';
    int ans = 0;
    if(s[index] == '?'){
        if(notpalindrome(x1) and notpalindrome(previous + '0')){ // x1 = 5 lenght , previous + '0 = 6
            ans += f(x1 , index + 1, s, dp);
        }
        if(notpalindrome(x2) and notpalindrome(previous + '1')){
            ans += f(x2, index+1, s , dp);
        }
    }
    else if(s[index] == '0'){
        if(notpalindrome(x1) and notpalindrome(previous + '0')){
            ans += f(x1, index +1 , s , dp);
        }
    }
    else if(s[index] == '1'){
        if(notpalindrome(x2) and notpalindrome(previous + '1')){
            ans += f(x2, index +1 , s , dp);
        }
    }
    return dp[index][previous] = ans;

}
void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    vector<map<string,int> > dp(n+5,map<string,int>());
    int ans = f("?????", 0, str,dp);
    if(ans) cout<<"POSSIBLE"<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
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

