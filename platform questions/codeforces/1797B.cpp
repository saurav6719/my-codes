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
    int n;
    int k;
    cin>>n>>k;
    vector<vector<int> > input(n, vector<int> (n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>input[i][j];
        }
    }
    int a = 0;
    int b = n-1;
    
    while(a<b){
        int c = 0;
        int d = n-1;
        while(c<n and d>=0){
            // debug(input[a][c]);
            // debug(input[b][d]);
            if(input[a][c] != input[b][d]) k--;
            c++;
            d--;
        }
        a++;
        b--;
        // debug(a);
        // debug(b);
    }
    if(a==b){
        int c = 0;
        int d = n-1;
        while(c<=n/2 and d>=n/2){
            if(input[a][c] != input[b][d]) k--;
            c++;
            d--;
        }        
    }
    if(k<0){
        cout<<"NO"<<endl;
        return;
    }
    if(k%2 == 0){
        cout<<"YES"<<endl;
        return;
    }
    if(k&1){
        if(n&1) {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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

