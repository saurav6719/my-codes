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
    int n,m;
    cin>>n>>m;
    vector<vector<char> > input(n, vector<char> (m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>input[i][j];
        }
    }

    int mnrow = INT_MAX;
    int mncol = INT_MAX;
    int mxrow = INT_MIN;
    int mxcol = INT_MIN;
    for(int i = 0; i<n; i++){
        for(int j= 0; j<m; j++){
            if(input[i][j] == '#'){
                mnrow = min(mnrow, i+1);
                mncol = min(mncol, j+1);
                mxrow = max(mxrow, i+1);
                mxcol = max(mxcol , j+1);
            }
        }
    }

    int ans1;
    int ans2;
    ans1 = (mnrow+mxrow)/2;
    ans2 = (mncol + mxcol)/2;

    cout<<ans1<<" "<<ans2<<endl;

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

