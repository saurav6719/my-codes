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
    int a,b,k;
    cin>>a>>b>>k;

    vector<int> boys(k);
    vector<int> girls(k);

    for(int i = 0; i<k; i++){
        cin>>boys[i];
    }

    for(int i = 0; i<k; i++){
        cin>>girls[i];
    }

    vector<vector<int> > bo(a+1, vector<int> ());
    vector<vector<int> > gi(b+1, vector<int> ());


    for(int i = 0; i<k ;  i++){
        int curr = boys[i];
        bo[curr].push_back(i);
    }

    for(int i = 0; i<k ;  i++){
        int curr = girls[i];
        gi[curr].push_back(i);
    }
    int ans = 0;

    for(int i = 0;i<k; i++){
        int a1 = boys[i];
        int b1 = girls[i];
        int cc = 0;
        int x1 = lower_bound(bo[a1].begin(), bo[a1].end(), i) - bo[a1].begin();
        cc+= bo[a1].size() - x1;
        int x2 = lower_bound(gi[b1].begin(), gi[b1].end(), i) - gi[b1].begin();
        cc+= gi[b1].size() - x2;
        cc--;
        int xx = k-i-cc;
        ans += xx;
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
    while(t--){
        solve();
    }
return 0;
}

