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
    cin>>n;
    vector<vector<char> > grid;
    grid.resize(2, vector<char> (n));
    
    for(int i = 0; i<2; i++){
        for(int j = 0 ; j<n; j++){
            cin>>grid[i][j];
        }
    }

    if(grid[1][n-2] == '<'){
        cout<<"NO"<<endl;
        return;
    }

    int x = 1;
    int y = n-2;
    while(y>0){
        if(y>=1 and grid[((x+1)%2)][y-1] == '>'){
            debug(x);
            debug(y);
            x = (x+1)%2;
            y = y-1;
            continue;
        }
        if(y>=2 and grid[x][y-2] == '>'){
            y = y-2;
            continue;
        }
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    return;
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

