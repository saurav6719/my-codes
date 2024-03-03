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
void solve(){
    int a , b, c;
    cin>>a>>b>>c;
    
    // choosing a
    int reqc;
    int reqb;
    int reqa;
    bool ansa = false;
    int d = c - b;
    reqa = b-d;
    if(reqa % a == 0 and reqa / a > 0) ansa = true;

    //choosing b
    bool ansb = false;
    d = (c-a);
    if(d%2 != 0){
        goto gotto;
    }
    d/=2;
    reqb = a+d;
    if(reqb % b == 0 and reqb / b > 0 ) ansb = true;

    gotto: 
    //choosing c
    bool ansc = false;
    d = b-a;
    reqc = b+ d;
    if(reqc % c == 0 and reqc/c > 0 ) ansc = true;
    if(ansa or ansb or ansc ) {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
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

