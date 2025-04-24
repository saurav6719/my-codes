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
vector<int> fact;
void pre(){
    fact.resize(15);
    fact[0] = 1;
    for(int i = 1; i<15; i++){
        fact[i] = (i)*fact[i-1];
    }
}

int f(int m,int n){
    if(m==0 or n==0){
        return __builtin_popcountll(n);
    }
    //choose
    int cnt1;

    if(fact[m-1] <= n){
        cnt1 = 1 + f(m-1, n-fact[m-1]);
    }
    else cnt1 = INT_MAX;
    //not choose
    int cnt2 =  f(m-1, n);
    int cnt3 = __builtin_popcountll(n);
    return mn(cnt1, cnt2, cnt3);
}
void solve(){
    int n;
    cin>>n;

    cout<<f(15,n)<<endl;
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
    pre();
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

