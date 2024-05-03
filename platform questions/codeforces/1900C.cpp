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

int f(int i, vector<int> &leaf, vector<int> &parent, vector<char> &letter, vector<int> &lc, vector<int> &rc, vector<int> &dp){
    if(i == 1) return 0;
    if(dp[i] != -1) return dp[i];
    int currleaf = i;
    int par = parent[currleaf];
    if((lc[par] == currleaf and letter[par] == 'L') or (rc[par] == currleaf and letter[par] == 'R')){
        return dp[i] = f(par,leaf,parent,letter,lc,rc,dp);
    }
    else return dp[i] = 1+ f(par, leaf, parent, letter,lc,rc,dp);
}
void solve(){
    int n;
    cin>>n;
    vector<char> letter(n+1);
    for(int i = 1; i<=n; i++){
        cin>>letter[i];
    }
    vector<int> dp(n+1, -1);
    vector<int> parent(n+1);
    vector<int> lc(n+1);
    vector<int> rc(n+1);
    vector<int> leaf;
    for(int i = 1; i<=n; i++){
        int f;
        int s;
        cin>>f>>s;
        if(f == 0 and s==0) {
            leaf.push_back(i);
        }
        if(f!=0) parent[f] = i;
        if(s!=0) parent[s] = i;
        lc[i] = f;
        rc[i] = s;
    }
    //print(leaf);
    int cost = INT_MAX;
    for(int i = 0; i<leaf.size(); i++){
        // debug(leaf[i]);
        // debug(f(leaf[i],leaf,parent,letter,lc,rc,dp));
        cost = min(cost, f(leaf[i],leaf,parent,letter,lc,rc,dp));
    }
    // debug(letter[2]);
    // print(dp);
    cout<<cost<<endl;
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

