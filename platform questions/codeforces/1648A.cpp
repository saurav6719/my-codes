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
    int m;
    cin>>m;
    vector<vector<int> >input(n, vector<int> (m));
    vector<vector<int> >x(100001, vector<int> ());
    vector<vector<int> >y(100001, vector<int> ());
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>input[i][j];
            x[input[i][j]].push_back(i);
            y[input[i][j]].push_back(j);
        }
    }

    int ans = 0;
    for(int i = 0; i<x.size(); i++){
        sort(x[i].begin(), x[i].end());
    }

    for(int i = 0; i<y.size(); i++){
        sort(y[i].begin(), y[i].end());
    }

    vector<vector<int> > x_copy = x;

    vector<vector<int> > y_copy = y;

    // print(y[1]);
    // print(y[2]);
    // print(y[3]);

    for(int i = 0; i<x.size(); i++){
        for(int j = 1; j<x[i].size(); j++){
            x[i][j] += x[i][j-1];
        }
    }

    print(x[1]);

    for(int i = 0; i<y.size(); i++){
        for(int j = 1; j<y[i].size(); j++){
            y[i][j] += y[i][j-1];
        }
    }

    for(int i =0; i<x.size(); i++){
        for(int j = 0; j<x[i].size(); j++){
            int last = x[i][x[i].size()-1];
            debug(last);
            debug(x[i][j]);
            ans += ((last - x[i][j])-(x_copy[i][j]*(x[i].size()-1 - j)));   
            debug(ans);     
            
        }
    }

    for(int i =0; i<y.size(); i++){
        for(int j = 0; j<y[i].size(); j++){
            int last = y[i][y[i].size()-1];
            // debug(last);
            // debug(y[i][j]);
            ans += ((last - y[i][j])-(y_copy[i][j]*(y[i].size()-1 - j)));    
            //debug(ans);            
        }
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

