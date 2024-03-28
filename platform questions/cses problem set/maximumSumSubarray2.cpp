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
#define INF 1e18
using namespace std;

/* write core logic here */

struct DescendingOrder {
    bool operator() (const int& a, const int& b) const {
        return a > b; // Compare in descending order
    }
};

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> prf(n+1);

    for(int i = 1; i<=n; i++){
        cin>>prf[i];
    }

    
    prf[0] = 0;
    for(int i = 1; i<=n; i++){
        prf[i] += prf[i-1];
    }

    print(prf);
    set<pair<int,int> > st;

    int ans = -INF;
    for(int i = a; i<=b; i++){
        st.insert({prf[i], i});
    }
    for(int i = 1; i<= n-a+1; i++){
        ans = max(ans , st.rbegin() -> first - prf[i-1]);
        st.erase({prf[i + a-1], i+a-1});
        if(i+b <=n ) st.insert({prf[i+b], i+b});
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

