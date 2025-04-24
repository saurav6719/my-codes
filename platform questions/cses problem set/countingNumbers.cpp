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
 
int dp[20][15][15][2][2];
int f(string &s , int idx, int last , int slast, bool smaller, bool ltaken){
    if(last == slast and ltaken) return 0;
    if((idx == s.size())) {
        return 1;
    }
    if(dp[idx][last][slast][smaller][ltaken] != -1 ) return dp[idx][last][slast][smaller][ltaken];
    int ans = 0;
    int loop;
    if(smaller){
        loop = 9;
    }
    else{
        loop = s[idx] - '0';
    }
    for(int i = 0; i<= loop ; i++){
        bool newsmaller;
        if(smaller) newsmaller = true;
        else{
            if(i == s[idx] - '0') newsmaller = false;
            else newsmaller = true;
        }
        bool newltaken;
        if(ltaken) newltaken = true;
        else{
            if(i==0) newltaken = false;
            else newltaken = true;
        }
        ans += f(s, idx+1 , i, last, newsmaller, newltaken);
    }
    return dp[idx][last][slast][smaller][ltaken] = ans;
}
void solve(){
    int a;
    int b;
    cin>>a>>b;
    string stra = to_string(a-1);
    string strb = to_string(b);
    
    int rans = 0;
    if(b<=9){
        rans = b+1;
    }
    else{
        int xx = strb[0] - '0';
        xx *= 10;
        xx += strb[1] - '0';
        memset(dp, -1, sizeof dp);
        
        for(int i  = 0; i<=9; i++){
            for(int j = 0; j<=9; j++){
                if(i*10 + j > xx) continue;
                if(i*10 + j == xx){
                    rans += f(strb, 2, j , i, 0, (i*10 + j == 0 ? 0 : 1));
                }
                else rans += f(strb , 2 , j, i, 1, (i*10 + j == 0 ? 0 : 1));
                // debug(i*10 +j);
                // debug(rans);
            }
        }
    }
 
    
 
    int lans = 0;
    if(a<=9){
        lans = a;
    }
    else{
        int yy = stra[0] - '0';
        yy *= 10;
        yy += stra[1] - '0';
        debug(yy);
        memset(dp, -1, sizeof dp);
        for(int i  = 0; i<=9; i++){
            for(int j = 0; j<=9; j++){
                if(i*10 + j > yy) continue;
                if(i*10 + j == yy){
                    lans += f(stra , 2, j, i, 0, (i*10 + j == 0 ? 0 : 1));
                }
                else lans += f(stra , 2 , j, i, 1, (i*10 + j == 0 ? 0 : 1));
            }
        }
    }
 
    //debug(lans);
 
    cout<<rans-lans;
 
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